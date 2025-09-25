typedef struct _VIDEO_PORT_I2C_INTERFACE {
  IN USHORT                  Size;
  IN USHORT                  Version;
  OUT PVOID                  Context;
  OUT PINTERFACE_REFERENCE   InterfaceReference;
  OUT PINTERFACE_DEREFERENCE InterfaceDereference;
  OUT PI2C_START             I2CStart;
  OUT PI2C_STOP              I2CStop;
  OUT PI2C_WRITE             I2CWrite;
  OUT PI2C_READ              I2CRead;
} VIDEO_PORT_I2C_INTERFACE, *PVIDEO_PORT_I2C_INTERFACE;