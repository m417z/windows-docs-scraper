typedef struct tagNMTVSTATEIMAGECHANGING {
  NMHDR     hdr;
  HTREEITEM hti;
  int       iOldStateImageIndex;
  int       iNewStateImageIndex;
} NMTVSTATEIMAGECHANGING, *LPNMTVSTATEIMAGECHANGING;