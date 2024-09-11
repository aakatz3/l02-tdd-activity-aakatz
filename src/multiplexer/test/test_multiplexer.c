#include <multiplexer.h>
#include <stdint.h>
#include <stdbool.h>
#include <unity.h>
#include <malloc.h>
// See
// https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityGettingStartedGuide.md

static struct tmux_inst* tmuxisnt;

void setUp(void) {
  tmuxisnt = malloc(sizeof(tmuxisnt));
}

void tearDown(void) {
  // Clean stuff up here
}

/* Your tests here! */

void test_SetAddressGetAddress(void){
    setAddress(tmuxisnt,3);
    TEST_ASSERT_EQUAL(3, tmuxisnt->sel);
    TEST_ASSERT_EQUAL(3, getAddress(tmuxisnt));
}

void test_EnableDisable(void){
    enable(tmuxisnt);
    TEST_ASSERT_TRUE(tmuxisnt->enabled);
    TEST_ASSERT_TRUE(isEnabled(tmuxisnt));
    disabled(tmuxisnt);
    TEST_ASSERT_FALSE(tmuxisnt->enabled);
    TEST_ASSERT_FALSE(isEnabled(tmuxisnt));
}

//void test_sampleSucceed(void) { TEST_ASSERT_EQUAL(1, 1); }
//
//void test_sampleFail(void) { TEST_ASSERT_EQUAL(1, 2); }
//
//void test_sampleIgnored(void) { TEST_IGNORE(); }
