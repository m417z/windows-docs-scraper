#define CopyFromUserAligned(Destination, Source, Length, Alignment)                                 \
            do {                                                                                    \
                ExProbeAlignment((Source), (Length), (Alignment));                                  \
                CopyFromUser((Destination), (Source), (Length));                                    \
            } while (0)