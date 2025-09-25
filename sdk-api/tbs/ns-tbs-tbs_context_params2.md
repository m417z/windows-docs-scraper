# TBS_CONTEXT_PARAMS2 structure

## Description

Specifies the version of the TBS context implementation. You must use this structure if your application works with both versions of TPM.

Applications interacting with just TPM 2.0 should pass a pointer to a **TBS_CONTEXT_PARAMS2** structure, with **version** set to TPM_VERSION_20, and **includeTpm20** set to 1.

Applications interacting with both TPM 1.2 and TPM 2.0 should pass a pointer to a **TBS_CONTEXT_PARAMS2** structure, with **version** set to TPM_VERSION_20, **includeTpm20** set to 1, and **includeTpm12** set to 1.

## Members

### `version`

The version of the TBS context implementation. This must be set to TPM_VERSION_20.

### `requestRaw`

### `includeTpm12`

### `includeTpm20`

### `asUINT32`

Used to access all of the bits in one variable.

### `includeTpm12:1`

Set to 1 if the TBS commands are to work on TPM 1.2.

### `includeTpm20:1`

Set to 1 if the TBS commands are to work on TPM 2.0.

### `requestRaw:1`

Set to 1 to request raw content.