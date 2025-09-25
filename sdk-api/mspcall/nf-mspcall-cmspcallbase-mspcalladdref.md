# CMSPCallBase::MSPCallAddRef

## Description

The
**MSPCallAddRef** method is the private AddRef method for the call object. MSP objects that keep references to the call object must call this method instead of the normal COM AddRef method so that the reference is kept on the MSP call object instead of on the aggregate TAPI call object. This is crucial to ensure correct object lifetimes. A template helper function, **MSPAddRefHelper**, is provided to help the derived MSP implement this method. All the derived MSP has to do in its implementation of this method is call "MSPAddRefHelper(this)". This is needed simply to provide the type of the derived class to the template helper function.

## See also

[CMSPCallBase](https://learn.microsoft.com/windows/desktop/api/mspcall/nl-mspcall-cmspcallbase)