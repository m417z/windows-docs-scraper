typedef enum _PEP_ACPI_RESOURCE_TYPE {
  PepAcpiMemory,
  PepAcpiIoPort,
  PepAcpiInterrupt,
  PepAcpiGpioIo,
  PepAcpiGpioInt,
  PepAcpiSpbI2c,
  PepAcpiSpbSpi,
  PepAcpiSpbUart,
  PepAcpiExtendedMemory,
  PepAcpiExtendedIo
} PEP_ACPI_RESOURCE_TYPE;