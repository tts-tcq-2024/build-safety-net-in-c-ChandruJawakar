#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
    char soundex[5];
    generateSoundex("AX", soundex);
    ASSERT_STREQ(soundex, "A200");
}

TEST(SoundexTestsuite, DifferentConsonantsProduceDifferentCodes) {
    char soundex1[5];
    char soundex2[5];
    generateSoundex("AX", soundex1);
    generateSoundex("BX", soundex2);
    ASSERT_STRNE(soundex1, soundex2);
}

TEST(SoundexTestsuite, TruncateNamesLongerThanFourCharacters) {
    char soundex[5];
    generateSoundex("AXXXYY", soundex);
    ASSERT_STREQ(soundex, "A200");
}

TEST(SoundexTestsuite, NoDuplicateConsonantNumbers) {
    char soundex[5];
    generateSoundex("ABCFP", soundex);
    ASSERT_STREQ(soundex, "A121");
}



TEST(SoundexTestsuite, HandlesSingleCharacterInput) {
    char soundex[5];
    generateSoundex("A", soundex);
    ASSERT_STREQ(soundex, "A000");
}

TEST(SoundexTestsuite, HandlesCaseInsensitiveInput) {
    char soundex1[5];
    char soundex2[5];
    generateSoundex("AX", soundex1);
    generateSoundex("ax", soundex2);
    ASSERT_STREQ(soundex1, soundex2);
}
