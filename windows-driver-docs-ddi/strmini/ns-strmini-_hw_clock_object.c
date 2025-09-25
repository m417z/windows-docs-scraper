typedef struct _HW_CLOCK_OBJECT {
  PHW_CLOCK_FUNCTION HwClockFunction;
  ULONG              ClockSupportFlags;
  ULONG              Reserved[2];
} HW_CLOCK_OBJECT, *PHW_CLOCK_OBJECT;