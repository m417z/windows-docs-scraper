typedef struct _DVD_LAYER_DESCRIPTOR {
  UCHAR BookVersion : 4;
  UCHAR BookType : 4;
  UCHAR MinimumRate : 4;
  UCHAR DiskSize : 4;
  UCHAR LayerType : 4;
  UCHAR TrackPath : 1;
  UCHAR NumberOfLayers : 2;
  UCHAR Reserved1 : 1;
  UCHAR TrackDensity : 4;
  UCHAR LinearDensity : 4;
  ULONG StartingDataSector;
  ULONG EndDataSector;
  ULONG EndLayerZeroSector;
  UCHAR Reserved5 : 7;
  UCHAR BCAFlag : 1;
} DVD_LAYER_DESCRIPTOR, *PDVD_LAYER_DESCRIPTOR;