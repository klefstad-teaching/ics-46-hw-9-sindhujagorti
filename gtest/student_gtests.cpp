#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"

TEST(LadderTest, TransformableWords) {
  set<string> wordList = {"hit", "hot", "dot", "dog", "cog"};
  string start = "hit";
  string end = "cog";

  vector<string> ladder = generate_word_ladder(start, end, wordList);
  EXPECT_EQ(ladder.size(), 5); // Transformation: hit -> hot -> dot -> dog -> cog
}

TEST(LadderTest, NoTransformationPossible) {
  set<string> wordList = {"hot", "dot", "dog"};
  string start = "hit";
  string end = "cog";

  vector<string> ladder = generate_word_ladder(start, end, wordList);
  EXPECT_TRUE(ladder.empty()); // No valid transformation from "hit" to "cog"
}

TEST(LadderTest, SingleWordTransformation) {
  set<string> wordList = {"hot", "dot", "dog"};
  string start = "hit";
  string end = "hit";

  vector<string> ladder = generate_word_ladder(start, end, wordList);
  EXPECT_EQ(ladder.size(), 0); 
}
TEST(LadderTest, EmptyWordList) {
  set<string> wordList = {};
  string start = "hit";
  string end = "cog";

  vector<string> ladder = generate_word_ladder(start, end, wordList);
  EXPECT_TRUE(ladder.empty()); 
}

TEST(LadderTest, WordListWithMultiplePossiblePaths) {
  set<string> wordList = {"hit", "hot", "dot", "dog", "lot", "log", "cog"};
  string start = "hit";
  string end = "cog";

  vector<string> ladder = generate_word_ladder(start, end, wordList);
  EXPECT_EQ(ladder.size(), 5); 
}