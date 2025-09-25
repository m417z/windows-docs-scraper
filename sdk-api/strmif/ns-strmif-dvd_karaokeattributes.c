typedef struct tagDVD_KaraokeAttributes {
  BYTE                   bVersion;
  BOOL                   fMasterOfCeremoniesInGuideVocal1;
  BOOL                   fDuet;
  DVD_KARAOKE_ASSIGNMENT ChannelAssignment;
  WORD                   wChannelContents[8];
} DVD_KaraokeAttributes;