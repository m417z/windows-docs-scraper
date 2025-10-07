typedef union _WINBIO_PRESENCE_PROPERTIES {
  struct {
    RECT BoundingBox;
    LONG Distance;
  } FacialFeatures;
  struct {
    RECT  EyeBoundingBox_1;
    RECT  EyeBoundingBox_2;
    POINT PupilCenter_1;
    POINT PupilCenter_2;
    LONG  Distance;
  } Iris;
} WINBIO_PRESENCE_PROPERTIES, *PWINBIO_PRESENCE_PROPERTIES;