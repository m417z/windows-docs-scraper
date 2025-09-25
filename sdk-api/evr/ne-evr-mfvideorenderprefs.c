typedef enum MFVideoRenderPrefs {
  MFVideoRenderPrefs_DoNotRenderBorder = 0x1,
  MFVideoRenderPrefs_DoNotClipToDevice = 0x2,
  MFVideoRenderPrefs_AllowOutputThrottling = 0x4,
  MFVideoRenderPrefs_ForceOutputThrottling = 0x8,
  MFVideoRenderPrefs_ForceBatching = 0x10,
  MFVideoRenderPrefs_AllowBatching = 0x20,
  MFVideoRenderPrefs_ForceScaling = 0x40,
  MFVideoRenderPrefs_AllowScaling = 0x80,
  MFVideoRenderPrefs_DoNotRepaintOnStop = 0x100,
  MFVideoRenderPrefs_Mask = 0x1ff
} ;