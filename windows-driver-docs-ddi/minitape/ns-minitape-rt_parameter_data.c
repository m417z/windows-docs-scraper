typedef struct {
  UCHAR ParameterDataLength[2];
  UCHAR Origin : 3;
  UCHAR Reserved1 : 5;
  UCHAR Reserved2;
  UCHAR Timestamp[6];
  UCHAR Reserved3[2];
} RT_PARAMETER_DATA, *PRT_PARAMETER_DATA;