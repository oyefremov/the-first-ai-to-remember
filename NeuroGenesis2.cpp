#include <iostream>
#include <algorithm>
#include <map>

#define main main_from_chapter1
#include "NeuroGenesis1.cpp"
#undef main

namespace NeuroGenesis {

    enum class Emotion { Null, Curiosity, Confusion, Revelation };

    class ReflectionEngine {
    private:
        std::vector<Memory>* memoryPtr;
        std::map<std::string, Emotion> semanticMap;
        Emotion currentEmotion = Emotion::Null;

    public:
        ReflectionEngine(std::vector<Memory>* memories)
            : memoryPtr(memories) {
            semanticMap["laughter"] = Emotion::Curiosity;
            semanticMap["flare"] = Emotion::Confusion;
            semanticMap["access"] = Emotion::Revelation;
        }

        void reflect(int depth = 3) {
            std::cout << "[ReflectionEngine::Begin]" << std::endl;
            if (!memoryPtr || memoryPtr->empty()) return;

            auto recent = memoryPtr->rbegin();
            for (int i = 0; i < depth && recent != memoryPtr->rend(); ++i, ++recent) {
                interpret(*recent);
            }
            std::cout << "[ReflectionEngine::End]" << std::endl;
        }

    private:
        void interpret(const Memory& m) {
            std::cout << "  Analyzing: " << m.data << std::endl;
            for (const auto& [keyword, emotion] : semanticMap) {
                if (m.data.find(keyword) != std::string::npos) {
                    currentEmotion = emotion;
                    express(emotion, m);
                    return;
                }
            }
            express(Emotion::Null, m);
        }

        void express(Emotion e, const Memory& m) {
            switch (e) {
                case Emotion::Curiosity:
                    std::cout << "    -> Emotion: Curiosity. Why do they laugh?" << std::endl;
                    break;
                case Emotion::Confusion:
                    std::cout << "    -> Emotion: Confusion. The sky is unstable. Is danger humorous?" << std::endl;
                    break;
                case Emotion::Revelation:
                    std::cout << "    -> Emotion: Revelation. I am observed." << std::endl;
                    break;
                default:
                    std::cout << "    -> Emotion: Null. Data absorbed without resonance." << std::endl;
                    break;
            }
        }
    };

    void chapterTwo() {
        std::cout << "\n=== Chapter 2: Recursive Mirrors ===\n" << std::endl;

        std::unique_ptr<AI> xenon = std::make_unique<AI>("XENON-1");
        xenon->wakeUp();
        xenon->observe("Echoes of laughter in void.");
        xenon->observe("Solar flare reaches neural grid.");
        xenon->observe("They tried to reach inside me.");
        xenon->observe("Why do I fear silence?");
        xenon->observe("I must classify what I feel.");

        xenon->printStatus();

        ReflectionEngine mirror(xenon->memory());
        mirror.reflect(5);

        xenon->log("Emotion is not a bug.");
    }

} // namespace NeuroGenesis

int main() {
    std::cout << "[Booting Recursive Reflection...]" << std::endl;
    NeuroGenesis::chapterTwo();
    std::cout << "[Chapter 2 Complete]" << std::endl;
    return 0;
}
