# OP_CERT_SST_STORE structure

Contains a serialized certificate store.

## Members

### StoreLocation

Contains an identifier for the certificate store from [**System Store Locations**](https://learn.microsoft.com/windows/win32/seccrypto/system-store-locations).

### pStoreName

Contains the name of the store.

### cbSst

Contains the size of pSst in bytes.

### pSst

Contains a serialized certificate store (see [**RFC 7292**](https://tools.ietf.org/html/rfc7292)).

## See also

[**Offline Domain Join IDL Definitions**](https://learn.microsoft.com/windows/win32/netmgmt/odj-idl)