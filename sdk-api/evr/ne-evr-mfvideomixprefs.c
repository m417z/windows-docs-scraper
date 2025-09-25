typedef enum _MFVideoMixPrefs {
  MFVideoMixPrefs_ForceHalfInterlace = 0x1,
  MFVideoMixPrefs_AllowDropToHalfInterlace = 0x2,
  MFVideoMixPrefs_AllowDropToBob = 0x4,
  MFVideoMixPrefs_ForceBob = 0x8,
  MFVideoMixPrefs_EnableRotation = 0x10,
  MFVideoMixPrefs_Mask = 0x1f
} MFVideoMixPrefs;