typedef struct {
  BOOLEAN                 DefaultToBiosPolicy;
  UCHAR                   LevelCount;
  struct {
    UCHAR BatteryLevel;
    UCHAR Brightness;
  };
  __unnamed_struct_019e_4 Level[1];
} VIDEO_BRIGHTNESS_POLICY, *PVIDEO_BRIGHTNESS_POLICY;