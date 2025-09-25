#define CopyFromModeAligned(Destination, Source, Length, Mode, Alignment)                           \
            do {                                                                                    \
                if ((Mode) != KernelMode) {                                                         \
                    ExProbeAlignment((Source), (Length), (Alignment));                              \
                }                                                                                   \
                CopyFromMode((Destination), (Source), (Length), (Mode));                            \
            } while (0)