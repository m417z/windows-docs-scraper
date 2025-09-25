typedef struct _WINBIO_PIPELINE {
  HANDLE                      SensorHandle;
  HANDLE                      EngineHandle;
  HANDLE                      StorageHandle;
  PWINBIO_SENSOR_INTERFACE    SensorInterface;
  PWINBIO_ENGINE_INTERFACE    EngineInterface;
  PWINBIO_STORAGE_INTERFACE   StorageInterface;
  PWINIBIO_SENSOR_CONTEXT     SensorContext;
  PWINIBIO_ENGINE_CONTEXT     EngineContext;
  PWINIBIO_STORAGE_CONTEXT    StorageContext;
  PWINBIO_FRAMEWORK_INTERFACE FrameworkInterface;
} WINBIO_PIPELINE, *PWINBIO_PIPELINE;