typedef enum AM_SEEKING_SeekingCapabilities {
  AM_SEEKING_CanSeekAbsolute = 0x1,
  AM_SEEKING_CanSeekForwards = 0x2,
  AM_SEEKING_CanSeekBackwards = 0x4,
  AM_SEEKING_CanGetCurrentPos = 0x8,
  AM_SEEKING_CanGetStopPos = 0x10,
  AM_SEEKING_CanGetDuration = 0x20,
  AM_SEEKING_CanPlayBackwards = 0x40,
  AM_SEEKING_CanDoSegments = 0x80,
  AM_SEEKING_Source = 0x100
} AM_SEEKING_SEEKING_CAPABILITIES;