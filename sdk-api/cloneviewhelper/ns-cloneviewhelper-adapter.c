typedef struct tagAdapter {
  WCHAR   AdapterName[128];
  int     numSources;
  Sources sources[1];
} Adapter;