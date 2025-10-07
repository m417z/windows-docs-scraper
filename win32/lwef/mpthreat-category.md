# MPTHREAT\_CATEGORY enumeration

Possible threat categories.

## Constants

Threat category | Description
-|-
 **MP\_THREAT\_CATEGORY\_INVALID** | The threat category doesn't exist, or has been misspelled.
 **MP\_THREAT\_CATEGORY\_ADWARE** | A potentially unwanted application that displays advertisements.
 **MP\_THREAT\_CATEGORY\_SPYWARE** | Malware that transmits information about the device or user, without the user's consent or knowledge.
 **MP\_THREAT\_CATEGORY\_PASSWORDSTEALER** | An application that collects and/or transmits a password to an attacker.
**MP\_THREAT\_CATEGORY\_TROJANDOWNLOADER** | A trojan that downloads malware or potentially unwanted applications to an infected device.
 **MP\_THREAT\_CATEGORY\_WORM** | Self-propagating malicious software that can automatically distribute itself through network connections.
**MP\_THREAT\_CATEGORY\_BACKDOOR** | Malware that provides a means of bypassing normal security and authentication protocols on a device.
 **MP\_THREAT\_CATEGORY\_REMOTEACCESSTROJAN** | A trojan that provides remote access to a computer.
**MP\_THREAT\_CATEGORY\_TROJAN** | Malicious software that disguises itself as legitimate software.
 **MP\_THREAT\_CATEGORY\_EMAILFLOODER** | Malware the sends a large volume of email to a target.
 **MP\_THREAT\_CATEGORY\_KEYLOGGER** | Malware that records the user's keystrokes, potentially stealing passwords and other sensitive data.
 **MP\_THREAT\_CATEGORY\_DIALER** | Malware that makes unauthorized phone calls, often at premium rates.
 **MP\_THREAT\_CATEGORY\_MONITORINGSOFTWARE** | A potentially unwanted application that monitors user activity, such as what the user types on their keyboard or views on their screen.
 **MP\_THREAT\_CATEGORY\_BROWSERMODIFIER** | A potentially unwanted application that changes web browser settings without the user's consent.
 **MP\_THREAT\_CATEGORY\_COOKIE** | Data that a Web server sends to a browser, allowing it to save information about the user, such as web application settings, on repeated visits.
 **MP\_THREAT\_CATEGORY\_BROWSERPLUGIN** | Software that lets a standard web browser display and run specific types of content, such as media files, animated images, and interactive forms.
 **MP\_THREAT\_CATEGORY\_AOLEXPLOIT** | Malware that attacks users of the AOL Internet service, often by retrieving passwords or modifying settings.
 **MP\_THREAT\_CATEGORY\_NUKER** | Malware designed to crash a device or make it less stable.
 **MP\_THREAT\_CATEGORY\_SECURITYDISABLER** | Malware that disables security settings or products.
 **MP\_THREAT\_CATEGORY\_JOKEPROGRAM** | An application designed to amuse or scare a user, without actually harming the device.
 **MP\_THREAT\_CATEGORY\_HOSTILEACTIVEXCONTROL** | An ActiveX control designed by an attacker to harm a device. An ActiveX control is a kind of browser add-on specific to Internet Explorer.
 **MP\_THREAT\_CATEGORY\_SOFTWAREBUNDLER** | Software that installs other potentially unwanted applications, such as adware or spyware. The license agreement of the bundling software may require these other components in order to function.
 **MP\_THREAT\_CATEGORY\_STEALTHNOTIFIER** | Malware that connects to a remote server through a stealth connection to notify an attacker that the malware has been installed.
 **MP\_THREAT\_CATEGORY\_SETTINGSMODIFIER** | A potentially unwanted application that changes a user's settings without the user's knowledge or consent.
 **MP\_THREAT\_CATEGORY\_TOOLBAR** | A potentially unwanted application (PUA) that installs a toolbar on the user's web browser; often bundled with additional PUA, such as adware.
 **MP\_THREAT\_CATEGORY\_REMOTECONTROLSOFTWARE** | A potentially unwanted application that provides remote access to a device.
 **MP\_THREAT\_CATEGORY\_TROJANFTP** | A trojan that uses an FTP server to allow an attacker to upload or download files from a device.
 **MP\_THREAT\_CATEGORY\_POTENTIALUNWANTEDSOFTWARE** | Also known as *potentially unwanted application* or *PUA*; software that may behave in an overly intrusive way, which the user may not have expected or fully consented to.
 **MP\_THREAT\_CATEGORY\_ICQEXPLOIT** | A trojan that attacks the ICQ messaging service, often by retrieving passwords or tampering with settings.
 **MP\_THREAT\_CATEGORY\_TROJANTELNET** | A trojan that installs a telnet server on a user's computer without the user's knowledge or consent.
 **MP\_THREAT\_CATEGORY\_EXPLOIT** | Malicious code that takes advantage of a vulnerability on a device or system.
 **MP\_THREAT\_CATEGORY\_FILESHARINGPROGRAM** | A potentially unwanted application that opens a device to peer-to-peer sharing of the device's files.
 **MP\_THREAT\_CATEGORY\_MALWARE\_CREATION\_TOOL** | An application that can automatically generate malicious files.
 **MP\_THREAT\_CATEGORY\_REMOTE\_CONTROL\_SOFTWARE** | A potentially unwanted application that allows for remote access to a device.
 **MP\_THREAT\_CATEGORY\_TOOL** | A utility that helps an attacker perform malicious actions on a device.
 **MP\_THREAT\_CATEGORY\_TROJAN\_DENIALOFSERVICE** | A trojan that is designed to send a large volume of network requests to a target as part of a denial of service (DoS) attack.
 **MP\_THREAT\_CATEGORY\_TROJAN\_DROPPER** | A trojan that downloads and installs malware or potentially unwanted applications on a target.
 **MP\_THREAT\_CATEGORY\_TROJAN\_MASSMAILER** | A trojan that sends a large volume of email to a target, intended to overwhelm the target's inbox.
 **MP\_THREAT\_CATEGORY\_TROJAN\_MONITORINGSOFTWARE** | A trojan that monitors user activity, such as what the user types on their keyboard or views on their screen.
 **MP\_THREAT\_CATEGORY\_TROJAN\_PROXYSERVER** | A proxy server installed by a trojan, providing what appears to be an uninterrupted Internet connection while allowing unauthorized access to the infected device.
 **MP\_THREAT\_CATEGORY\_VIRUS** | Malware that replicates, commonly by infecting other files in the system, thus allowing the execution of the malware code and its propagation when those files are activated.
 **MP\_THREAT\_CATEGORY\_KNOWN** | An unspecified malware threat.
 **MP\_THREAT\_CATEGORY\_UNKNOWN** | An unspecified malware threat that has not yet been defined.
 **MP\_THREAT\_CATEGORY\_SPP** | Anti-piracy technology that requires each installation of a Windows product be activated with Microsoft.
 **MP\_THREAT\_CATEGORY\_BEHAVIOR** | A type of detection based on file actions that are often associated with malicious activity.
 **MP\_THREAT\_CATEGORY\_VULNERABILTIY** | Any weakness, administrative process, or activity that makes a device susceptible to exploit by a threat.
 **MP\_THREAT\_CATEGORY\_POLICY** | A set of rules defined by an administrator, that control features on desktop and mobile devices such as software updates.

## Requirements

| Requirement | Value |
|-|-|
| Minimum supported client | Windows 8 (desktop apps only) |
| Minimum supported server | Windows Server 2012 (desktop apps only) |
| Header | MpClient.h |