# OleCreatePictureIndirect function

## Description

Creates a new picture object initialized according to a [PICTDESC](https://learn.microsoft.com/windows/desktop/api/olectl/ns-olectl-pictdesc) structure.

## Parameters

### `lpPictDesc` [in]

Pointer to a caller-allocated structure containing the initial state of the picture. The specified structure can be **NULL** to create an uninitialized object, in the event the picture needs to initialize via [IPersistStream::Load](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststream-load).

### `riid` [in]

Reference to the identifier of the interface describing the type of interface pointer to return in *lplpvObj*.

### `fOwn` [in]

If **TRUE**, the picture object is to destroy its picture when the object is destroyed. If **FALSE**, the caller is responsible for destroying the picture.

### `lplpvObj` [out]

Address of pointer variable that receives the interface pointer requested in riid. Upon successful return, this parameter contains the requested interface pointer on the newly created object. If the call is successful, the caller is responsible for calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) through this interface pointer when the new object is no longer needed. If the call fails, the value is set to **NULL**.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **E_NOINTERFACE** | The object does not support the interface specified in riid. |
| **E_POINTER** | The address in *pPictDesc* or *lplpvObj* is not valid. For example, it may be **NULL**. |

## Remarks

 The *fOwn* parameter indicates whether the picture is to own the GDI picture handle for the picture it contains, so that the picture object will destroy its picture when the object itself is destroyed. The function returns an interface pointer to the new picture object specified by the caller in the *riid* parameter. A [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) is built into this call. The caller is responsible for calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) through the interface pointer returned.

## See also

[OleLoadPicture](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-oleloadpicture)

[PICTDESC](https://learn.microsoft.com/windows/desktop/api/olectl/ns-olectl-pictdesc)