typedef enum tagDVD_TIMECODE_FLAGS {
  DVD_TC_FLAG_25fps = 0x1,
  DVD_TC_FLAG_30fps = 0x2,
  DVD_TC_FLAG_DropFrame = 0x4,
  DVD_TC_FLAG_Interpolated = 0x8
} DVD_TIMECODE_FLAGS;