#include "prephase.h"



void GalaxyObject::push(StarObject object) {
    collector[index] = object;
    index += 1;
}

void StarObject::push(PlanetObject object) {
    collector[index] = object;
    index += 1;
}

void PlanetObject::push(BiomeObject object) {
    collector[index] = object;
    index += 1;
}

void BiomeObject::push(Cell object) {
    collector[index] = object;
    index += 1;
}




void GalaxyObject::push_container(Star object) {
    containing[index] = object;
    stars += 1;
}

void StarObject::push_container(Planet object) {
    containing[index] = object;
    planets += 1;
}

void PlanetObject::push_container(Biome object) {
    containing[index] = object;
    biomes += 1;
}


void GalaxyObject::set_stars(int number) {
    stars = number;
}

int GalaxyObject::get_stars() {
    return stars;
}





    BiomeObject  WorldObject::generate_b(const int RANGE) {
        BiomeObject biome;
        for(int c = 0; c < RANGE; c++) { // cells
            Cell local1;
            biome.collector[c] = local1;
        }
    return biome;
    }



    PlanetObject WorldObject::generate_p(const uint8_t n_biomes, const int n_cells) {
        PlanetObject planet;
        for(int c = 0; c < n_biomes; c++) { // biomes
            planet.collector[c] = generate_b(n_cells);
        }
    return planet;
    }



    StarObject   WorldObject::generate_s(const uint8_t n_planets, const uint8_t n_biomes, const int n_cells) {
        StarObject star;
        for(int c = 0; c < n_planets; c++) { // Planets
            star.collector[c] = generate_p(n_biomes, n_cells);
        }
        std::cout << "Star generated " << std::endl;
    return star;
    }



    void WorldObject::generate_cache_b(const int RANGE) {
        ofstream myfile;
        int localindex = planet_index;
        planet_index += 1;
        std::string filename = "data/Planet" + to_string(localindex);
        myfile.open (filename);

        for(int c = 0; c < RANGE; c++) { // cells
            Cell local1;
            std::string data = " {  cell :| "s + to_string(c) + " | type :| "s + to_string(local1.get_type()) + " | }; \n"s;
            myfile << data;
        }

        myfile.close();
    }


    void WorldObject::generate_star_system(const u_int8_t type, const u_int8_t n_planets , const int RANGE) {

        Star systemStar;
        std::vector<std::thread> threads;
        std::string zipName = "data/StarSystem" + to_string(one.get_stars()) + ".zip";

        one.set_stars(one.get_stars() + 1);

        for (int i = 0; i < n_planets; i++) {
            threads.push_back( std::thread{[&] {
                    generate_cache_b(RANGE);
                }
            });
        }

        for (auto &th : threads) {
            th.join();
            std::cout << "waiting for stop" << std::endl;
        }

        ZipArchive::Ptr archive = ZipFile::Open(zipName);
        

        for (int i = 0; i < n_planets; i++) {

            std::string planetsName = "data/Planet" + to_string(i);
            ZipArchiveEntry::Ptr entry = archive->CreateEntry(planetsName);
            assert(entry != nullptr);
            
            std::ifstream contentStream;
            contentStream.open(planetsName, std::ios::binary);
            assert(contentStream.is_open());
            DeflateMethod::Ptr ctx = DeflateMethod::Create();
            ctx->SetCompressionLevel(DeflateMethod::CompressionLevel::L1);

            entry->SetCompressionStream(   // data from contentStream are pumped here
                contentStream,
                ctx,
                ZipArchiveEntry::CompressionMode::Immediate
                );

            std::cout << planetsName << " planet added " << std::endl;

        }

        ZipFile::SaveAndClose(archive, zipName);
    }




WorldObject::WorldObject() {

    std::vector<std::thread> threads;
    PlanetObject currentPlanet;
    StarObject startStar;

    currentPlanet = generate_p(1, 3000000);

    generate_star_system(1, 5, 100000);

}