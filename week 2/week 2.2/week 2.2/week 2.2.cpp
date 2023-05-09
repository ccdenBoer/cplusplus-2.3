#include <iostream>
#include <string>

bool isGene(const std::string& gene) {
    if (gene.size() % 3 != 0) {
        return false;
    }

    if (gene.substr(0, 3) != "ATG") {
        return false;
    }

    const int geneLength = gene.size();
    const std::string stopCodons[] = { "TAG", "TAA", "TGA" };

    for (int i = 3; i < geneLength - 3; i += 3) {
        const std::string codon = gene.substr(i, 3);
        if (codon == "ATG") {
            return false;
        }

        for (const std::string& stopCodon : stopCodons) {
            if (codon == stopCodon) {
                return false;
            }
        }
    }

    const std::string lastCodon = gene.substr(geneLength - 3, 3);
    for (const std::string& stopCodon : stopCodons) {
        if (lastCodon == stopCodon) {
            return true;
        }
    }

    return false;
}

bool findGenes(std::string& genome) {
    const std::string startCodon = "ATG";
    const std::string stopCodons[] = { "TAG", "TAA", "TGA" };
    const int genomeLength = genome.size();
    bool geneFound = false;

    for (int i = 0; i < genomeLength - 2; ++i) {
        if (genome.substr(i, 3) == startCodon) {
            for (int j = i + 3; j < genomeLength - 2; j += 3) {
                const std::string codon = genome.substr(j, 3);
                bool isStopCodon = false;

                for (const std::string& stopCodon : stopCodons) {
                    if (codon == stopCodon) {
                        isStopCodon = true;
                        break;
                    }
                }

                if (isStopCodon) {
                    const std::string gene = genome.substr(i, j - i + 3);
                    if (isGene(gene)) {
                        std::cout << gene.substr(3, gene.size()-6) << std::endl;
                        geneFound = true;
                    }
                    break;
                }
            }
        }
    }
    return geneFound;
}

int main() {
    std::string genome;
    std::cout << "Enter a genome string: ";
    std::cin >> genome;



    bool geneFound = findGenes(genome);
 

    if (!geneFound) {
        std::cout << "No gene" << std::endl;
    }

    return 0;
}
