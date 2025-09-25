typedef struct SToolbarItem {
  IDockingWindow *ptbar;
  BORDERWIDTHS   rcBorderTool;
  LPWSTR         pwszItem;
  BOOL           fShow;
  HMONITOR       hMon;
} TOOLBARITEM, *LPTOOLBARITEM;