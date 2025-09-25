## Description

Accepts an array of profiles or a single [device link profile](https://learn.microsoft.com/windows/win32/wcs/using-device-profiles-with-wcs) and creates a color transform that applications can use to perform color mapping.

## Parameters

### `pahProfiles`

Pointer to an array of handles to the profiles to be used. The function determines whether the HPROFILEs contain International Color Consortium (ICC) or Windows Color System (WCS) profile information and processes them appropriately. When valid WCS profiles are returned by [**OpenColorProfileW**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-opencolorprofilew) and [**WcsOpenColorProfileW**](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/icm/nf-icm-wcsopencolorprofilew.md), these profile handles contain the combination of DMP, CAMP, and GMMP profiles.

### `nProfiles`

Specifies the number of profiles in the array. The maximum is 10.

### `padwIntent`

Pointer to an array of intents to use. Each intent is one of the following values:

**INTENT\_PERCEPTUAL**

**INTENT\_SATURATION**

**INTENT\_RELATIVE\_COLORIMETRIC**

**INTENT\_ABSOLUTE\_COLORIMETRIC**

GMMPs are a generalization of intents. There are two possible sources of intents: the "destination" profile and the intent list parameter to **CreateMultiProfileTransform**. The term "destination" is not used since all but two of the profiles in the profile list parameter will serve as first destination and then source.

For more information, see [Rendering Intents](https://learn.microsoft.com/windows/win32/wcs/rendering-intents).

### `nIntents`

Specifies the number of elements in the intents array: can either be 1 or the same value as *nProfiles*. For profile arrays that contain any WCS profiles, the first rendering intent is ignored and only *nProfiles* -1 elements are used for these profile arrays. The maximum number of *nIntents* is 10.

### `dwFlags`

Specifies flags used to control creation of the transform. See Remarks.

### `indexPreferredCMM`

Specifies the one-based index of the color profile that indicates what color management module (CMM) to use. The application developer may allow Windows to choose the CMM by setting this parameter to INDEX\_DONT\_CARE. See [Using Color Management Modules (CMM)](https://learn.microsoft.com/windows/win32/wcs/using-color-management-modules--cmm) Third party CMMs are only available for ICC workflows. Profile arrays containing WCS profiles will ignore this flag. It is also ignored when only ICC profiles are used and when the WCS\_ALWAYS flag is used.

## Return value

If this function succeeds, the return value is a handle to the color transform.

If this function fails, the return value is **NULL**. For extended error information, call **GetLastError**.

## Remarks

If a device link profile is being used, the function will fail if *nProfiles* is not set to 1.

The array of intents specifies how profiles should be combined. The *n*th intent is used for combining the *n*th profile in the array. If only one intent is specified, it is used for the first profile, and all other profiles are combined using [Match intent](https://learn.microsoft.com/windows/win32/wcs/rendering-intents).

The values in *dwFlags* are intended as hints only. The color management module must determine the best way to use them.

**Windows Vista**: Three new flags have been added that can be used with *dwFlags*:

| Flag | Description |
|-|-|
| **PRESERVEBLACK** | If this bit is set, the transform engine inserts the appropriate black generation GMMP as the last GMMP in the transform sequence. This flag only works in a pure WCS transform. |
| **SEQUENTIAL\_TRANSFORM** | If this bit is set, each step in the WCS processing pipeline is performed for every pixel in the image and no optimized color transform is built. This flag only works in a pure WCS transform.**Restrictions**: A transform created with the SEQUENTIAL\_TRANSFORM flag set may only be used in the thread on which it was created and only for one color translation call at a time. COM must be initialized prior to creating the sequential transform and must remain initialized for the lifetime of the transform object.<br> |
| **WCS\_ALWAYS** | If this bit is set, even all-ICC transforms will use the WCS code path. |

> [!Note]
>
> SEQUENTIAL\_TRANSFORM was inadvertently omitted from the icm.h header in the Windows Vista SDK. If you wish to use the SEQUENTIAL\_TRANSFORM flag, define it in your application as follows:
>
> \#define SEQUENTIAL\_TRANSFORM 0x80800000

For details, see [CMM Transform Creation Flags](https://learn.microsoft.com/windows/win32/wcs/cmm-transform-creation-flags). All of the flags mentioned there are supported for all types of transforms, except for FAST\_TRANSLATE and USE\_RELATIVE\_COLORIMETRIC, which only work in a pure ICC-to-ICC transform.

The **CreateMultiProfileTransform** function is used outside of a device context. Colors may shift when transforming from a color profile to the same color profile. This is due to precision errors. Therefore, a color transform should not be performed under these circumstances.

We recommend that there be only one GMMP between a source and destination DMP. Gamut boundary descriptions (GBDs) are created from the DMP/CAMP combinations. The subsequent GMMPs use the GDBs prior to them in the processing chain until there exists a DMP/CAMP GBD next in the sequence to be used. For example, assume a sequence DMP1, CAMP1, GMMP1, GMMP2, GMMP3, DMP2, CAMP2, GMMP4, GMMP5, CAMP3, DMP3. Then GMMP1, GMMP2 use GBD1 as their source and destination. Then GMMP3 uses GBD1 as source and GBD2 as destination. Then GMMP4 uses GBD2 as source and destination. Finally GMMP5 uses GBD2 as source and GBD3 as destination. This assumes no GMMP is identical to one next to it.

For WCS profiles, we recommend that the rendering intents be set to DWORD\_MAX in order to use the GMMP within the WCS profile handle. This is because the array of rendering intents takes precedence over the rendering intents or gamut mapping models specified or contained in the profiles specified by the HPROFILEs. The array of rendering intents references the default GMMP for those rendering intents. Ideally, only one gamut mapping is performed between a source and destination device by setting one or the other GMMP to **NULL** when creating the HPROFILE with WCS profile information. Any legacy application that uses a WCS DMP will invoke a sequence of GMMPs. GDBs are chosen based on DMPs and CAMPs. For intermediate GMMP gamut boundaries, the source and destination GBDs are used.

In summary, if *nIntents* == 1, then the first GMM is set based on the GMMP that is set as default\* for the *padwIntent* value, unless that value is DWORD\_MAX, in which case the embedded GMM information from the second profile is used (The embedded GMM information is either a GMMP or, in the case of an ICC profile, the baseline GMM corresponding to\*\* the intent from the profile header). The remainder of the GMMs are set based on the GMMP that is set as default\* for RelativeColorimetric.

If *nIntents* = *nProfiles* -1, then each GMM is set based on the GMMP that is set as default\* for the value in the *padwIntent* array at the corresponding index, except where *padwIntent* values are DWORD\_MAX. For values in the *padwIntent* array that are DWORD\_MAX, the GMMs at corresponding positions are set based on the embedded GMM information from the second of the two profiles whose gamuts are mapped by the GMM. (Again, the embedded GMM information is either a GMMP or, in the case of an ICC profile, the baseline GMM corresponding to\*\* the intent from the profile header).

If *nIntents* = *nProfiles*, then first intent is ignored and function behaves as it does in the case when *nIntents* = *nProfiles* -1.

Any other combination of *padwIntents* and *nIntents* will return an error.

\* "set as default" means that the default GMMP is queried using **WcsGetDefaultColorProfile** with its *profileManagementScope* parameter set to WCS\_PROFILE\_MANAGEMENT\_SCOPE\_CURRENT\_USER. This may return either current-user or system-wide defaults as described in the documentation for **WcsGetDefaultColorProfile**.

\*\* "GMM corresponding to" does not mean "GMM from the GMMP set as default for". Instead it means "a constant association between ICC profile intents and baseline GMM algorithms."

WCS transform support for ICC ColorSpace profiles is limited to RGB colorspace profiles. The following ICC profile types cannot be used in a CITE-processed transform, either a mixed WCS/ICC transform or an all-ICC transform with **WCS\_ALWAYS** set:

- Non-RGB ColorSpace profiles
- NamedColor profiles
- n-channel profiles (where n > 8)
- DeviceLink profiles
- Abstract profiles

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [COLOR Structure**](https://learn.microsoft.com/windows/win32/api/icm/ns-icm-color)
* [DeleteColorTransform](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-deletecolortransform)