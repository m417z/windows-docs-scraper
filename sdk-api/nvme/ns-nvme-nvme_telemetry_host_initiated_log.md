# NVME_TELEMETRY_HOST_INITIATED_LOG structure

## Description

Contains fields that specify the information in a Telemetry Host-Initiated Log page.

The **NVME_RESERVATION_NOTIFICATION_LOG** structure is returned by the Get Log Page command. For more information, see [NVME_CDW10_GET_LOG_PAGE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_get_log_page).

## Members

### `LogIdentifier`

Indicates the log identifier.

### `Reserved0`

Bytes 1-4 are reserved.

### `OrganizationID`

Indicates an IEEE Organizationally Unique Identifier (OUI) that is the Organization ID.

### `Area1LastBlock`

Bytes 8-9 indicate the last block of Area 1.

### `Area2LastBlock`

Bytes 10-11 indicate the last block of Area 2.

### `Area3LastBlock`

Bytes 12-13 indicate the last block of Area 3.

### `Reserved1`

Bytes 14-381 are reserved.

### `ControllerInitiatedDataAvailable`

Byte 382 indicates whether controller initiated data is available.

### `ControllerInitiatedDataGenerationNumber`

Byte 383 indicates the generation number of controller initiated data when it is available.

### `ReasonIdentifier`

Bytes 384-511 indicate the reason identifier.

## Remarks

All NVMe Telemetry Data Blocks are 512 bytes in size.

## See also