# CMSPAddress::GetDynamicTerminalClasses

## Description

The
**GetDynamicTerminalClasses** method is called by our wrapper methods to get an array of dynamic terminal classes that can be used on this address. The semantics of the arguments are the same as for
[GetStaticTerminals](https://learn.microsoft.com/windows/desktop/api/mspaddr/nf-mspaddr-cmspaddress-getstaticterminals). This method simply asks the Terminal Manager for the terminal classes. MSPs that implement additional, custom types of dynamic terminals, or that want to disallow the use of certain dynamic terminal classes from the Terminal Manager, would want to override this method.

## Parameters

### `pdwNumClasses` [out]

Pointer to number of dynamic terminals.

### `pTerminalClasses` [out]

Pointer to array of
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interfaces.

## See also

[CMSPAddress](https://learn.microsoft.com/windows/desktop/api/mspaddr/nl-mspaddr-cmspaddress)