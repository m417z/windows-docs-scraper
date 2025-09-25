typedef struct tagDVD_MenuAttributes {
  BOOL                     fCompatibleRegion[8];
  DVD_VideoAttributes      VideoAttributes;
  BOOL                     fAudioPresent;
  DVD_AudioAttributes      AudioAttributes;
  BOOL                     fSubpicturePresent;
  DVD_SubpictureAttributes SubpictureAttributes;
} DVD_MenuAttributes;