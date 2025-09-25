# ReleaseExclusiveCpuSets function

## Description

Opts out of CPU exclusivity, giving the app access to all cores, but at the cost of having to share them with other processes.

## Return value

The result of the operation.

## Remarks

You should call this function when you want to transition to shared mode (for example, if the app is running on a low-end device).

After this function is called, the app will still have access to other Game Mode resources, such as increased GPU prioritization. The app will also still get state transitions via [HasExpandedResources](https://learn.microsoft.com/previous-versions/windows/desktop/api/expandedresources/nf-expandedresources-hasexpandedresources).

As with [SetProcessDefaultCpuSets](https://learn.microsoft.com/windows/desktop/ProcThread/setprocessdefaultcpusets), **ReleaseExclusiveCpuSets** applies to the whole process.

This is a Win32 API that's only supported in UWP desktop and Xbox apps. It also requires the **expandedResources** restricted capability, which you can select by opening **Package.appxmanifest** in Visual Studio and navigating to the **Capabilities** tab. Alternatively, you can edit the file's code directly:

```xml

<Package
xmlns:rescap="http://schemas.microsoft.com/appx/manifest/foundation/windows10/restrictedcapabilities"
IgnorableNamespaces=" rescap">
	...
	<Capabilities>
		<rescap:Capability Name="expandedResources" />
	</Capabilities>
	...
</Package>
```

This capability is granted on a per-title basis; contact your account manager for more information. You can publish a UWP app with this capability to the Store if it targets desktop, but if it targets Xbox it will be rejected in certification.

The app must be in the foreground and have focus before exclusive resources are granted.