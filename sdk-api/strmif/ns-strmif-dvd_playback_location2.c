typedef struct tagDVD_PLAYBACK_LOCATION2 {
  ULONG             TitleNum;
  ULONG             ChapterNum;
  DVD_HMSF_TIMECODE TimeCode;
  ULONG             TimeCodeFlags;
} DVD_PLAYBACK_LOCATION2;