# IMFASFContentInfo::GetProfile

## Description

Retrieves an Advanced Systems Format (ASF) profile that describes the ASF content.

## Parameters

### `ppIProfile` [out]

Receives an [IMFASFProfile](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfprofile) interface pointer. The caller must release the interface. If the object does not have an ASF profile, this parameter receives the value **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The profile is set by calling either [IMFASFContentInfo::SetProfile](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfcontentinfo-setprofile) or [IMFASFContentInfo::ParseHeader](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfcontentinfo-parseheader).

The ASF profile object returned by this method does not include any of the **MF_PD_ASF_xxx** attributes (see [Presentation Descriptor Attributes](https://learn.microsoft.com/windows/desktop/medfound/presentation-descriptor-attributes)). To get these attributes, do the following:

1. Call [IMFASFContentInfo::GeneratePresentationDescriptor](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfcontentinfo-generatepresentationdescriptor) to get the ASF presentation descriptor. You can query the presentation descriptor for the **MF_PD_ASF_xxx** attributes.
2. (Optional.) Call [MFCreateASFProfileFromPresentationDescriptor](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-mfcreateasfprofilefrompresentationdescriptor) to convert the presentation descriptor into an ASF profile. The profile object created by this function contains the **MF_PD_ASF_xxx** attributes.

An ASF profile is a template for file encoding, and is intended mainly for creating ASF content. If you are reading an existing ASF file, it is recommended that you use the presentation descriptor to get information about the file. One exception is that the profile contains the mutual exclusion and stream prioritization objects, which are not exposed directly from the presentation descriptor.

## See also

[ASF ContentInfo Object](https://learn.microsoft.com/windows/desktop/medfound/asf-contentinfo-object)

[IMFASFContentInfo](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfcontentinfo)

[Initializing the ContentInfo Object of a New ASF File](https://learn.microsoft.com/windows/desktop/medfound/initializing-the-contentinfo-object-of-a-new-asf-file)