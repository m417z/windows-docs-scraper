typedef struct SENSOR_COLLECTION_LIST {
  ULONG             AllocatedSizeInBytes;
  ULONG             Count;
  SENSOR_VALUE_PAIR List[1];
} SENSOR_COLLECTION_LIST, *PSENSOR_COLLECTION_LIST;