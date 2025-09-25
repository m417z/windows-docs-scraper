# WINBIO_STORAGE_RECORD structure

## Description

The **WINBIO_STORAGE_RECORD** structure contains a biometric template and associated data in a standard format. This structure is used to pass information between an engine adapter and a storage adapter.

## Members

### `Identity`

Pointer to a [WINBIO_IDENTITY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-identity) structure that contains the GUID or SID of the storage record.

### `SubFactor`

A [WINBIO_BIOMETRIC_SUBTYPE](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-biometric-subtype-constants) value that specifies the biometric sub-factor associated with the template data.

**Important**

Do not attempt to validate the value supplied for the *SubFactor* value. The Windows Biometrics Service will validate the supplied value before passing it through to your implementation. If the value is **WINBIO_SUBTYPE_NO_INFORMATION** or **WINBIO_SUBTYPE_ANY**, then validate where appropriate.

### `IndexVector`

Pointer to a contiguous array of **ULONG** values. These values represent the bucket address assigned to the biometric template by the engine adapter.

### `IndexElementCount`

The number of **ULONG** values in the array specified by the *IndexVector* field.

### `TemplateBlob`

Pointer to an array of bytes that contains the biometric template data.

### `TemplateBlobSize`

Size, in bytes, of the template specified by the *TemplateBlob* parameter.

### `PayloadBlob`

Pointer to an array of bytes that contains integrity checking data. This field is used only by adapters for removable devices that contain embedded storage.

### `PayloadBlobSize`

Size, in bytes, of the data specified by the *PayloadBlob* parameter.

## Remarks

The **WINBIO_STORAGE_RECORD** structure and the memory it points to are the property of the component that created the structure. In particular, the component determines when the structure is deleted and when its embedded pointers become invalid. When other components are given temporary access to this structure, they must follow the rules governing structure lifetime set by the owning component.

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)

[Plug-in Structures](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-structures)

[StorageAdapterGetCurrentRecord](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_get_current_record_fn)