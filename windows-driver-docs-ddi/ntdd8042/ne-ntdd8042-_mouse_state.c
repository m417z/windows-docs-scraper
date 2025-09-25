typedef enum _MOUSE_STATE {
  MouseIdle,
  XMovement,
  YMovement,
  ZMovement,
  MouseExpectingACK,
  MouseResetting
} MOUSE_STATE, *PMOUSE_STATE;