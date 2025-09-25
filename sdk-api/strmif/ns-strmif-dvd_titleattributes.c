typedef struct tagDVD_TitleMainAttributes {
  union {
    DVD_TITLE_APPMODE AppMode;
    DVD_HMSF_TIMECODE TitleLength;
  };
  DVD_VideoAttributes             VideoAttributes;
  ULONG                           ulNumberOfAudioStreams;
  DVD_AudioAttributes             AudioAttributes[8];
  DVD_MultichannelAudioAttributes MultichannelAudioAttributes[8];
  ULONG                           ulNumberOfSubpictureStreams;
  DVD_SubpictureAttributes        SubpictureAttributes[32];
} DVD_TitleAttributes;