# PROCESS_MITIGATION_POLICY enumeration

## Description

Represents the different process mitigation policies.

## Constants

### `ProcessDEPPolicy`

The data execution prevention (DEP) policy of the process.

### `ProcessASLRPolicy`

The Address Space Layout Randomization (ASLR) policy of the process.

### `ProcessDynamicCodePolicy`

The policy that turns off the ability of the process to generate dynamic code or modify existing executable code.

### `ProcessStrictHandleCheckPolicy`

The process will receive a fatal error if it manipulates an invalid handle. Useful for preventing downstream problems in a process due to handle misuse.

### `ProcessSystemCallDisablePolicy`

Disables the ability to use NTUser/GDI functions at the lowest layer.

### `ProcessMitigationOptionsMask`

Returns the mask of valid bits for all the mitigation options on the system. An application can set many mitigation options without querying the operating system for mitigation options by combining bitwise with the mask to exclude all non-supported bits at once.

### `ProcessExtensionPointDisablePolicy`

The policy that prevents some built-in third party extension points from being turned on, which prevents legacy extension point DLLs from being loaded into the process.

### `ProcessControlFlowGuardPolicy`

The Control Flow Guard (CFG) policy of the process.

### `ProcessSignaturePolicy`

The policy of a process that can restrict image loading to those images that are either signed by Microsoft, by the Windows Store, or by Microsoft, the Windows Store and the Windows Hardware Quality Labs (WHQL).

### `ProcessFontDisablePolicy`

The policy that turns off the ability of the process to load non-system fonts.

### `ProcessImageLoadPolicy`

The policy that turns off the ability of the process to load images from some locations, such a remote devices or files that have the low mandatory label.

### `ProcessSystemCallFilterPolicy`

The system call filter policy of the process.

### `ProcessPayloadRestrictionPolicy`

The payload restriction policy of the process.

### `ProcessChildProcessPolicy`

The child process policy of the process.

### `ProcessSideChannelIsolationPolicy`

The side channel isolation policy of the process.

### `ProcessUserShadowStackPolicy`

Windows 10, version 2004 and above: The policy regarding user-mode Hardware-enforced Stack Protection for the process.

### `ProcessRedirectionTrustPolicy`

The RedirectionGuard policy of the process.

### `ProcessUserPointerAuthPolicy`

The user pointer authentication policy of the process.

### `ProcessSEHOPPolicy`

The Structured Exception Handling Overwrite Protection (SEHOP) policy of the process.

### `MaxProcessMitigationPolicy`

Ends the enumeration.

## Remarks

## See also

[GetProcessMitigationPolicy function](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getprocessmitigationpolicy), [SetProcessMitigationPolicy function](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy)