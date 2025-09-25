typedef struct _PWM_CONTROLLER_INFO {
  SIZE_T     Size;
  ULONG      PinCount;
  PWM_PERIOD MinimumPeriod;
  PWM_PERIOD MaximumPeriod;
} PWM_CONTROLLER_INFO;