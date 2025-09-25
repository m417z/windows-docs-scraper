typedef struct {
  KSNODEPROPERTY NodeProperty;
  ULONG          DevSpecificId;
  ULONG          DeviceInfo;
  ULONG          Length;
} KSNODEPROPERTY_AUDIO_DEV_SPECIFIC, *PKSNODEPROPERTY_AUDIO_DEV_SPECIFIC;