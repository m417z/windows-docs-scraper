typedef struct tagDVD_AudioAttributes {
  DVD_AUDIO_APPMODE  AppMode;
  BYTE               AppModeData;
  DVD_AUDIO_FORMAT   AudioFormat;
  LCID               Language;
  DVD_AUDIO_LANG_EXT LanguageExtension;
  BOOL               fHasMultichannelInfo;
  DWORD              dwFrequency;
  BYTE               bQuantization;
  BYTE               bNumberOfChannels;
  DWORD              dwReserved[2];
} DVD_AudioAttributes;