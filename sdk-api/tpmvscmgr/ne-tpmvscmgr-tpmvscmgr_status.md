# TPMVSCMGR_STATUS enumeration

## Description

Provides predefined status codes to represent the progress of the TPM virtual smart card manager.

## Constants

### `TPMVSCMGR_STATUS_VTPMSMARTCARD_INITIALIZING:0`

Initializing the virtual smart card manager.

### `TPMVSCMGR_STATUS_VTPMSMARTCARD_CREATING`

Creating the virtual smart card manager.

### `TPMVSCMGR_STATUS_VTPMSMARTCARD_DESTROYING`

Destroying the virtual smart card manager.

### `TPMVSCMGR_STATUS_VGIDSSIMULATOR_INITIALIZING`

Initializing the virtual smart card simulator.

### `TPMVSCMGR_STATUS_VGIDSSIMULATOR_CREATING`

Creating the virtual smart card simulator.

### `TPMVSCMGR_STATUS_VGIDSSIMULATOR_DESTROYING`

Destroying the virtual smart card simulator.

### `TPMVSCMGR_STATUS_VREADER_INITIALIZING`

Initializing the virtual smart card reader.

### `TPMVSCMGR_STATUS_VREADER_CREATING`

Creating the virtual smart card reader.

### `TPMVSCMGR_STATUS_VREADER_DESTROYING`

Destroying the virtual smart card reader.

### `TPMVSCMGR_STATUS_GENERATE_WAITING`

Waiting for the TPM smart card device.

### `TPMVSCMGR_STATUS_GENERATE_AUTHENTICATING`

Authenticating to the TPM smart card.

### `TPMVSCMGR_STATUS_GENERATE_RUNNING`

Generating the file system on the TPM smart card.

### `TPMVSCMGR_STATUS_CARD_CREATED`

Creation of the TPM smart card is complete.

### `TPMVSCMGR_STATUS_CARD_DESTROYED`

Destruction of the TPM smart card is complete.

## Remarks

These status codes are sent from the TPM virtual smart card manager COM server to the caller through the status callback interface, [ITpmVirtualSmartCardManagerStatusCallback](https://learn.microsoft.com/windows/desktop/api/tpmvscmgr/nn-tpmvscmgr-itpmvirtualsmartcardmanagerstatuscallback). Status callback interface implementations must interpret the status codes based on their predefined meanings and, if applicable, load localized message strings and update the user interface.