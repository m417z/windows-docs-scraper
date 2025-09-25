# IPersistSerializedPropStorage::SetFlags

## Description

Toggles the property store object between the read-only and read/write state.

## Parameters

### `flags` [in]

Type: **PERSIST_SPROPSTORE_FLAGS**

The *flags* parameter takes one of the following values to set options for the behavior of the property storage:

#### FPSPS_DEFAULT (0x00000000)

**Windows 7 and later**. The property store object is read/write.

#### FPSPS_READONLY (0x00000001)

The property store object is read-only.

#### FPSPS_TREAT_NEW_VALUES_AS_DIRTY (0x00000002)

**Introduced in Windows 8**. New property values that are added to the property store through the [IPropertyStore::SetValue](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb761475(v=vs.85)) method will cause the [IPersistStream::IsDirty](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststream-isdirty) method to return S_OK. If this flag is not set, the addition of new property values to the property store does not affect the value returned by **IPersistStream::IsDirty**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Read/write is the default setting. **IPersistSerializedPropStorage::SetFlags** can be called at any time to toggle the read-only and read/write state of the property store.

In versions of Windows before Windows 7, callers can assign a literal zero value directly into the *flags* parameter to set the read/write state. As of Windows 7, the FPSPS_DEFAULT flag value should be used instead.