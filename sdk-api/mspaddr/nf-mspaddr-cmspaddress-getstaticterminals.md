# CMSPAddress::GetStaticTerminals

## Description

The
**GetStaticTerminals** method is called by our wrapper methods (
[get_StaticTerminals](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminalsupport-get_staticterminals) and
[EnumerateStaticTerminals](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminalsupport-enumeratestaticterminals)) to get an array of static terminals that can be used on this address. This method updates the address' internal list of terminals by calling
[UpdateTerminalList](https://learn.microsoft.com/windows/desktop/api/mspaddr/nf-mspaddr-cmspaddress-updateterminallist) if the list is not up to date. If the *ppTerminals* parameter is **NULL** or the **pdwNumTerminals* parameter is not large enough to hold all the terminal pointers, this method simply returns (as **pdwNumTerminals*) the number of terminals available. If *ppTerminals* is non-**NULL** and **pdwNumTerminals* is large enough, it **AddRefs** each terminal pointer and places the array of terminal pointers in **ppTerminals*, setting **pdwNumTerminals* to the number of terminal pointers returned. If the derived MSP wants to change the set of terminals returned, it will probably override
[UpdateTerminalList](https://learn.microsoft.com/windows/desktop/api/mspaddr/nf-mspaddr-cmspaddress-updateterminallist) rather than overriding this method.

## Parameters

### `pdwNumTerminals` [out]

Pointer to number of static terminals.

### `ppTerminals` [out]

Pointer to array of
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interfaces.

## See also

[CMSPAddress](https://learn.microsoft.com/windows/desktop/api/mspaddr/nl-mspaddr-cmspaddress)