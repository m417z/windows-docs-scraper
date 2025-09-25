typedef struct INTERACTION_CONTEXT_OUTPUT2 {
  INTERACTION_ID     interactionId;
  INTERACTION_FLAGS  interactionFlags;
  POINTER_INPUT_TYPE inputType;
  UINT32             contactCount;
  UINT32             currentContactCount;
  float              x;
  float              y;
  union {
    INTERACTION_ARGUMENTS_MANIPULATION manipulation;
    INTERACTION_ARGUMENTS_TAP          tap;
    INTERACTION_ARGUMENTS_CROSS_SLIDE  crossSlide;
  } arguments;
} INTERACTION_CONTEXT_OUTPUT2;