# CMSPAddress::MSPAddressAddRef

## Description

The
**MSPAddressAddRef** method is the private AddRef method for the address. MSP objects that keep references to the address must call this method instead of the normal COM AddRef method so that the reference is kept on the MSP address object instead of on the aggregate TAPI address object. This is crucial to ensure correct object lifetimes. A template helper function, **MSPAddRefHelper**, is provided to help the derived MSP implement this method. All the derived MSP has to do in its implementation of this method is call "MSPAddRefHelper(this)". This is needed simply to provide the type of the derived class to the template helper function.

## See also

[CMSPAddress](https://learn.microsoft.com/windows/desktop/api/mspaddr/nl-mspaddr-cmspaddress)