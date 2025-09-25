# USER_INPUT_STRING_TYPE enumeration

## Description

The `USER_INPUT_STRING_TYPE` enumeration type indicates the type of string to obtain from the user in [IPhotoAcquireProgressCB::GetUserInput](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireprogresscb-getuserinput).

## Constants

### `USER_INPUT_DEFAULT:0`

Indicates that any string is allowed.

### `USER_INPUT_PATH_ELEMENT:0x1`

Indicates that the string will not accept characters that are illegal in file or directory names (such as * or /).

## See also

[Enumeration Types](https://learn.microsoft.com/previous-versions/windows/desktop/acquisition/enumeration-types)

[IPhotoAcquireProgressCB::GetUserInput](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireprogresscb-getuserinput)

[IUserInputString::GetStringType](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iuserinputstring-getstringtype)