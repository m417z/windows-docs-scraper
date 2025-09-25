# TPMVSCMGR_ERROR enumeration

## Description

Provides predefined error codes to represent the contexts of errors from the TPM virtual smart card manager.

## Constants

### `TPMVSCMGR_ERROR_IMPERSONATION:0`

Failed to impersonate the caller.

### `TPMVSCMGR_ERROR_PIN_COMPLEXITY`

Ensure that your PIN/PUK meets the length or complexity requirements of your organization.

### `TPMVSCMGR_ERROR_READER_COUNT_LIMIT`

The limit of the number of smart card readers has been reached.

### `TPMVSCMGR_ERROR_TERMINAL_SERVICES_SESSION`

TPM virtual smart card management cannot be used within a Terminal Services session.

### `TPMVSCMGR_ERROR_VTPMSMARTCARD_INITIALIZE`

Failed to initialize the virtual smart card manager.

### `TPMVSCMGR_ERROR_VTPMSMARTCARD_CREATE`

Failed to create the virtual smart card manager.

### `TPMVSCMGR_ERROR_VTPMSMARTCARD_DESTROY`

Failed to destroy the virtual smart card manager.

### `TPMVSCMGR_ERROR_VGIDSSIMULATOR_INITIALIZE`

Failed to initialize the virtual smart card simulator.

### `TPMVSCMGR_ERROR_VGIDSSIMULATOR_CREATE`

Failed to create the virtual smart card simulator.

### `TPMVSCMGR_ERROR_VGIDSSIMULATOR_DESTROY`

Failed to destroy the virtual smart card simulator.

### `TPMVSCMGR_ERROR_VGIDSSIMULATOR_WRITE_PROPERTY`

Failed to configure the virtual smart card simulator.

### `TPMVSCMGR_ERROR_VGIDSSIMULATOR_READ_PROPERTY`

Failed to find the specified virtual smart card simulator.

### `TPMVSCMGR_ERROR_VREADER_INITIALIZE`

Failed to initialize the virtual smart card reader.

### `TPMVSCMGR_ERROR_VREADER_CREATE`

Failed to create the virtual smart card reader.

### `TPMVSCMGR_ERROR_VREADER_DESTROY`

Failed to destroy the virtual smart card reader.

### `TPMVSCMGR_ERROR_GENERATE_LOCATE_READER`

Failed to connect to the TPM smart card.

### `TPMVSCMGR_ERROR_GENERATE_FILESYSTEM`

Failed to generate the file system on the TPM smart card.

### `TPMVSCMGR_ERROR_CARD_CREATE`

Unable to create the TPM smart card.

### `TPMVSCMGR_ERROR_CARD_DESTROY`

Unable to destroy the TPM smart card.

## Remarks

These error codes are sent from the TPM virtual smart card manager COM server to the caller through the status callback interface, [ITpmVirtualSmartCardManagerStatusCallback](https://learn.microsoft.com/windows/desktop/api/tpmvscmgr/nn-tpmvscmgr-itpmvirtualsmartcardmanagerstatuscallback). Status callback interface implementations must interpret the error codes based on their predefined meanings and, if applicable, load localized message strings and update the user interface.