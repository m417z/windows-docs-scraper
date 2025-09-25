# CredMarshalTargetInfo function

## Description

Serializes the specified target into an array of byte values.

## Parameters

### `InTargetInfo` [in]

A pointer to a [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) version of the [CREDENTIAL_TARGET_INFORMATION](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-credential_target_informationa) structure that specifies the target to serialize.

### `Buffer` [out]

The serialized array of byte values that represents the target specified by the *InTargetInfo* parameter.

### `BufferSize`

The size, in bytes, of the *Buffer* array.

## Return value

If the function succeeds, it returns **STATUS_SUCCESS**.

If the function fails, it returns an error code that indicates the reason it failed.