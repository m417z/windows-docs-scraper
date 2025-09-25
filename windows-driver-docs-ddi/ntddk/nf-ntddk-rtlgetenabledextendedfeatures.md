# RtlGetEnabledExtendedFeatures function

## Description

The **RtlGetEnabledExtendedFeatures** routine returns a mask of extended processor features that are enabled by the system.

## Parameters

### `FeatureMask` [in]

A 64-bit feature mask. This parameter indicates a set of extended processor features for which the caller requests information about whether the features are enabled. If a mask bit is one, the caller requests information about the feature that corresponds to this mask bit. The caller sets all other mask bits to zero. Set this parameter to (ULONG64)(-1) to get the mask of all enabled features. To determine whether a particular set of features is enabled, set this parameter to the bitwise OR of one or more [XSTATE_MASK_XXX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesaveextendedprocessorstate) flag bits.

## Return value

**RtlGetEnabledExtendedFeatures** returns a 64-bitmask of enabled extended processor features. The routine calculates this mask as the intersection (bitwise AND) between all enabled features and the value of the *FeatureMask* parameter. For more information about the features that are indicated by this return value, see [XSTATE_MASK_XXX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesaveextendedprocessorstate).

**RtlGetEnabledExtendedFeatures** returns 0 if the XSAVE and XRSTOR instructions are disabled by the system. This happens even if the system supports XSTATE_MASK_LEGACY_FLOATING_POINT and XSTATE_MASK_LEGACY_SSE features. Use **ExIsProcessorFeaturePresent** or CPUID to determine the availability of x87, MMX, and SSE processor features on x86 or x64 systems.

## Remarks

Another routine, [ExIsProcessorFeaturePresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exisprocessorfeaturepresent), indicates whether an extended processor feature is available. Unlike **RtlGetEnabledExtendedFeatures**, however, it does not indicate whether the operating system has enabled the feature for use by kernel-mode drivers.

## See also

[ExIsProcessorFeaturePresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exisprocessorfeaturepresent)