// Translated by: Fabio Olimpieri <fabio.olimpieri@tin.it>
// Updated by: Roberto Togni <see AUTHORS for email address>
// Updated by: PaulTT <paultt@hackerjournal.it>

// Updated to help_mp-en.h v1.222

// TODO: change references to DOCS/HTML/en/... to DOCS/HTML/it/... when they will be updated
//
// ========================= MPlayer help ===========================

#ifdef HELP_MP_DEFINE_STATIC
static char help_text[]=
"Uso:   mplayer [opzioni] [url|percorso/]nome_file\n"
"\n"
"Opzioni di base: (vedi la pagina man per la lista completa)\n"
" -vo <drv[:dev]>  sceglie driver e dispositivo uscita video ('-vo help' lista)\n"
" -ao <drv[:dev]>  sceglie driver e dispositivo uscita audio ('-ao help' lista)\n"
#ifdef HAVE_VCD
" vcd://<trackno>  legge (S)VCD (Super Video CD) (dispositivo raw, non montato)\n"
#endif
#ifdef USE_DVDREAD
" dvd://<titleno>  legge titolo/traccia DVD dal dispositivo anzich� da file\n"
" -alang/-slang    sceglie lingua audio/sottotitoli DVD (cod naz. 2 caratteri)\n"
#endif
" -ss <timepos>    cerca una determinata posizione (in secondi o in hh:mm:ss) \n"
" -nosound         non riproduce l'audio\n"
" -fs              opzioni schermo intero (o -vm, -zoom, vedi pagina man)\n"
" -x <x> -y <y>    imposta la risoluzione dello schermo (usare con -vm o -zoom)\n"
" -sub <file>      file sottotitoli da usare (vedi anche -subfps, -subdelay)\n"
" -playlist <file> specifica il file della playlist\n"
" -vid x -aid y    seleziona il flusso video (x) ed audio (y) da riprodurre\n"
" -fps x -srate y  cambia il rate del video (x fps) e dell'audio (y Hz)\n"
" -pp <quality>    abilita filtro postelaborazione (vedi pagina man x dettagli)\n"
" -framedrop       abilita lo scarto dei fotogrammi (per macchine lente)\n"
"\n"
"Tasti principali: (vedi pagina man per lista, controlla anche input.conf)\n"
" <-  o  ->        va indietro/avanti di 10 secondi\n"
" su o gi�         va avanti/indietro di  1 minuto\n"
" pagsu o paggi�   va avanti/indietro di 10 minuti\n"
" < o >            va indietro/avanti nella playlist\n"
" p o SPAZIO       pausa (premere un qualunque tasto per continuare)\n"
" q o ESC          ferma la riproduzione ed esce dal programma\n"
" + o -            regola il ritardo audio di +/- 0.1 secondi\n"
" o                modalit� OSD: niente / barra ricerca / barra ricerca + tempo\n"
" * o /            incrementa o decrementa il volume PCM\n"
" x o z            regola il ritardo dei sottotitoli di +/- 0.1 secondi\n"
" r o t            posizione alto/basso dei sottotitoli, vedi anche -vf expand\n"
"\n"
" * * * VEDI PAGINA MAN PER DETTAGLI, ULTERIORI OPZIONI AVANZATE E TASTI! * * *\n"
"\n";
#endif

#define MSGTR_SamplesWanted "Servono esempi di questo formato per migliorarne il supporto. Contatta sviluppatori.\n"

// ========================= MPlayer messages ===========================

// mplayer.c:

#define MSGTR_Exiting "\nIn uscita...\n"
#define MSGTR_ExitingHow "\nIn uscita... (%s)\n"
#define MSGTR_Exit_quit "Uscita"
#define MSGTR_Exit_eof "Fine del file"
#define MSGTR_Exit_error "Errore fatale"
#define MSGTR_IntBySignal "\nMPlayer interrotto dal segnale %d nel modulo: %s \n"
#define MSGTR_NoHomeDir "Impossibile trovare la HOME directory\n"
#define MSGTR_GetpathProblem "Problema in get_path(\"config\")\n"
#define MSGTR_CreatingCfgFile "Creo il file di configurazione: %s\n"
#define MSGTR_InvalidVOdriver "Nome del diver video di output non valido: %s\nUsa '-vo help' per avere una lista dei driver audio disponibili.\n"
#define MSGTR_InvalidAOdriver "Nome del diver audio di output non valido: %s\nUsa '-ao help' per avere una lista dei driver audio disponibili.\n"
#define MSGTR_CopyCodecsConf "(copia/linka etc/codecs.conf dai sorgenti di MPlayer a ~/.mplayer/codecs.conf)\n"
#define MSGTR_BuiltinCodecsConf "Utilizzo la versione interna predefinita di codecs.conf\n"
#define MSGTR_CantLoadFont "Impossibile caricare i font: %s\n"
#define MSGTR_CantLoadSub "Impossibile caricare i sottotitoli: %s\n"
#define MSGTR_DumpSelectedStreamMissing "dump: FATAL: manca il flusso selezionato!\n"
#define MSGTR_CantOpenDumpfile "Impossibile aprire il file di dump!!!\n"
#define MSGTR_CoreDumped "Core dumped ;)\n"
#define MSGTR_FPSnotspecified "FPS non specificato (o non valido) nell'intestazione! Usa l'opzione -fps!\n"
#define MSGTR_TryForceAudioFmtStr "Cerco di forzare l'uso della famiglia dei driver dei codec audio %d...\n"
#define MSGTR_CantFindAudioCodec "Impossibile trovare il codec per il formato audio 0x%X!\n"
#define MSGTR_RTFMCodecs "Leggi DOCS/HTML/en/codecs.html!\n"
#define MSGTR_TryForceVideoFmtStr "Cerco di forzare l'uso della famiglia dei driver dei codec video %d...\n"
#define MSGTR_CantFindVideoCodec "Impossibile trovare il codec per il formato video 0x%X!\n"
#define MSGTR_CannotInitVO "FATALE: Impossibile inizializzare il driver video!\n"
#define MSGTR_CannotInitAO "Impossibile aprire/inizializzare il dispositivo audio -> NESSUN SUONO\n"
#define MSGTR_StartPlaying "Inizio la riproduzione...\n"

#define MSGTR_SystemTooSlow "\n\n"\
"       ****************************************************************\n"\
"       **** Il tuo sistema � troppo LENTO per questa riproduzione! ****\n"\
"       ****************************************************************\n"\
"Possibili cause, problemi, soluzioni:\n"\
"- Nella maggior parte dei casi: driver _audio_ danneggiato/bacato\n"\
"  - Prova -ao sdl o usa l'emulazione OSS di ALSA.\n"\
"  - Puoi anche provare con diversi valori di -autosync, 30 e' un buon inizio.\n"\
"- Output video lento\n"\
"  - Prova un altro -vo driver (-vo help per la lista) o prova con -framedrop!\n"\
"- CPU lenta\n"\
"  - Non provare a guardare grossi DVD/DivX su CPU lente! Prova qualche opzione\n"\
"di lavdopts, per es.  -vfm ffmpeg -lavdopts lowres=1:fast:skiploopfilter=all.\n"\
"- File rovinato\n"\
"  - Prova varie combinazioni di -nobps -ni -forceidx -mc 0.\n"\
"- Dispositivo lento (punti di mount NFS/SMB, DVD, VCD etc)\n"\
"  - Prova -cache 8192.\n"\
"- Stai usando -cache per riprodurre un file AVI senza interleave?\n"\
"  - Prova con -nocache.\n"\
"Leggi DOCS/HTML/en/video.html per suggerimenti su regolazione/accelerazione.\n"\
"Se nulla di ci� ti aiuta, allora leggi DOCS/HTML/en/bugreports.html!\n\n"

#define MSGTR_NoGui "MPlayer � stato compilato senza il supporto della GUI!\n"
#define MSGTR_GuiNeedsX "La GUI di MPlayer richiede X11!\n"
#define MSGTR_Playing "Riproduco %s\n"
#define MSGTR_NoSound "Audio: nessun suono!!!\n"
#define MSGTR_FPSforced "FPS forzato a %5.3f  (ftime: %5.3f)\n"
#define MSGTR_CompiledWithRuntimeDetection "Compilato con riconoscimento CPU in esecuzione.\n"
#define MSGTR_CompiledWithCPUExtensions "Compilato per CPU x86 con estensioni:"
#define MSGTR_AvailableVideoOutputDrivers "Driver di output video disponibili:\n"
#define MSGTR_AvailableAudioOutputDrivers "Driver di output audio disponibili:\n"
#define MSGTR_AvailableAudioCodecs "Codec audio disponibili:\n"
#define MSGTR_AvailableVideoCodecs "Codec video disponibili:\n"
#define MSGTR_AvailableAudioFm "Famiglie/driver di codec audio disponibili (compilati):\n"
#define MSGTR_AvailableVideoFm "Famiglie/driver di codec video disponibili (compilati):\n"
#define MSGTR_AvailableFsType "Modi disponibili a schermo intero:\n"
#define MSGTR_UsingRTCTiming "Sto utilizzando la temporizzazione hardware RTC di Linux (%ldHz)\n"
#define MSGTR_CannotReadVideoProperties "Video: impossibile leggere le propriet�\n"
#define MSGTR_NoStreamFound "Nessun flusso trovato\n"
#define MSGTR_ErrorInitializingVODevice "Errore aprendo/inizializzando il dispositivo uscita video (-vo) selezionato!\n"
#define MSGTR_ForcedVideoCodec "Codec video forzato: %s\n"
#define MSGTR_ForcedAudioCodec "Codec audio forzato: %s\n"
#define MSGTR_Video_NoVideo "Video: nessun video!!!\n"
#define MSGTR_NotInitializeVOPorVO "\nFATALE: Impossibile inizializzare i filtri video (-vf) o l'output video (-vo)!\n"
#define MSGTR_Paused "\n  =====  PAUSA  =====\r"
#define MSGTR_PlaylistLoadUnable "\nImpossibile caricare la playlist %s\n"
#define MSGTR_Exit_SIGILL_RTCpuSel \
"- MPlayer � stato interrotto dal segnale 'Istruzione illegale'.\n"\
"  Potrebbe essere un errore nel codice di rilevamento tipo di processore...\n"\
"  leggi DOCS/HTML/en/bugreports.html.\n"
#define MSGTR_Exit_SIGILL \
"- MPlayer � stato interrotto dal segnale 'Istruzione illegale'.\n"\
"  Solitamente questo avviene quando si esegue il programma su un processore\n"\
"  diverso da quello per cui � stato compilato/ottimizzato.\n"\
"  Verificalo!\n"
#define MSGTR_Exit_SIGSEGV_SIGFPE \
"- MPlayer � stato interrotto per un errore nell'uso della CPU/FPU/RAM.\n"\
"  Ricompila MPlayer con --enable-debug e crea un backtrace ed un disassemblato\n"\
"  con 'gdb'. Per dettagli DOCS/HTML/en/bugreports_what.html#bugreports_crash.\n"
#define MSGTR_Exit_SIGCRASH \
"- MPlayer � andato in crash. Questo non dovrebbe accadere.\n"\
"  Pu� essere un errore nel codice di MPlayer _o_ nei tuoi driver _o_ nella tua\n"\
"  versione di gcc. Se ritieni sia colpa di MPlayer, perfavore leggi\n"\
"  DOCS/HTML/en/bugreports.html e segui quelle istruzioni. Non possiamo\n"\
"  aiutarti, e non lo faremo, se non ci dai queste informazioni quando segnali\n"\
"  un possibile problema.\n"
#define MSGTR_LoadingConfig "Carico configurazione '%s'\n"
#define MSGTR_AddedSubtitleFile "SUB: aggiunto file sottotitoli (%d): %s\n"
#define MSGTR_RemovedSubtitleFile "SUB: rimosso file sottotitoli (%d): %s\n"
#define MSGTR_ErrorOpeningOutputFile "Errore durante l'apertura del file [%s] per la scrittura!\n"
#define MSGTR_CommandLine "CommandLine:"
#define MSGTR_RTCDeviceNotOpenable "Apertura di %s fallita: %s (dovrebbe esser leggibile dall'utente.)\n"
#define MSGTR_LinuxRTCInitErrorIrqpSet "Linux RTC: errore di init in ioctl (rtc_irqp_set %lu): %s\n"
#define MSGTR_IncreaseRTCMaxUserFreq "Prova aggiungendo \"echo %lu > /proc/sys/dev/rtc/max-user-freq\"\n"\
"agli script di avvio del sistema.\n"
#define MSGTR_LinuxRTCInitErrorPieOn "Linux RTC: errore di init in ioctl (rtc_pie_on): %s\n"
#define MSGTR_UsingTimingType "Uso la temporizzazione %s.\n"
#define MSGTR_NoIdleAndGui "L'opzione -idle non pu� essere usata con GMPlayer.\n"
#define MSGTR_MenuInitialized "Menu inizializzato: %s\n"
#define MSGTR_MenuInitFailed "Inizializzazione Menu fallita.\n"
#define MSGTR_Getch2InitializedTwice "WARNING: getch2_init chiamata 2 volte!\n"
#define MSGTR_DumpstreamFdUnavailable "Non posso fare il dump di questo flusso - nessun descrittore file disponibile.\n"
#define MSGTR_FallingBackOnPlaylist "Provo infine a interpretare playlist %s...\n"
#define MSGTR_CantOpenLibmenuFilterWithThisRootMenu "Non riesco ad aprire il filtro video libmenu col menu base %s.\n"
#define MSGTR_AudioFilterChainPreinitError "Errore nel pre-init della sequenza di filtri audio!\n"
#define MSGTR_LinuxRTCReadError "Linux RTC: errore di lettura: %s\n"
// TODO: softsleep underflow ???
#define MSGTR_SoftsleepUnderflow "Attenzione! Softsleep underflow!\n"
#define MSGTR_DvdnavNullEvent "DVDNAV Evento NULL?!\n"
#define MSGTR_DvdnavHighlightEventBroken "DVDNAV Evento: Evento Highlight bacato\n"
#define MSGTR_DvdnavEvent "DVDNAV Evento: %s\n"
#define MSGTR_DvdnavHighlightHide "DVDNAV Evento: Nascondo Highlight\n"
#define MSGTR_DvdnavStillFrame "######################################## DVDNAV Evento: Still Frame: %d sec(s)\n"
#define MSGTR_DvdnavNavStop "DVDNAV Evento: Nav Stop\n"
#define MSGTR_DvdnavNavNOP "DVDNAV Evento: Nav NOP\n"
#define MSGTR_DvdnavNavSpuStreamChangeVerbose "DVDNAV Evento: Nav Cambio Flusso SPU: phys: %d/%d/%d logico: %d\n"
#define MSGTR_DvdnavNavSpuStreamChange "DVDNAV Evento: Nav Cambio Flusso SPU: phys: %d logico: %d\n"
#define MSGTR_DvdnavNavAudioStreamChange "DVDNAV Evento: Nav Cambio Flusso Audio: phys: %d logico: %d\n"
#define MSGTR_DvdnavNavVTSChange "DVDNAV Evento: Nav Cambio VTS\n"
#define MSGTR_DvdnavNavCellChange "DVDNAV Evento: Nav Cambio Cella\n"
#define MSGTR_DvdnavNavSpuClutChange "DVDNAV Evento: Nav Cambio CLUT SPU\n"
#define MSGTR_DvdnavNavSeekDone "DVDNAV Evento: Nev Ricerca eseguita\n"
#define MSGTR_MenuCall "Chiamata a Menu\n"

#define MSGTR_EdlOutOfMem "Non posso allocare abbastanza memoria per i dati EDL.\n"
#define MSGTR_EdlRecordsNo "Lette azioni EDL %d.\n"
#define MSGTR_EdlQueueEmpty "Non ci sono azioni EDL di cui curarsi.\n"
#define MSGTR_EdlCantOpenForWrite "Non posso aprire il file EDL [%s] per la scrittura.\n"
#define MSGTR_EdlCantOpenForRead "Non posso aprire il file EDL [%s] per la lettura.\n"
#define MSGTR_EdlNOsh_video "Non posso usare EDL senza video, disabilitate.\n"
#define MSGTR_EdlNOValidLine "Linea EDL invalida: %s\n"
#define MSGTR_EdlBadlyFormattedLine "Linea EDL scritta male [%d]: la ignoro.\n"
#define MSGTR_EdlBadLineOverlap "L'ultimo stop era a [%f]; lo start successivo a [%f].\n"\
"Le indicazioni devono essere in ordine, non posso sovrapporle. Ignoro.\n"
#define MSGTR_EdlBadLineBadStop "Lo stop deve essere dopo il tempo di start.\n"

// mplayer.c OSD

#define MSGTR_OSDenabled "abilitat"
#define MSGTR_OSDdisabled "disabilitat"
#define MSGTR_OSDnone "nessuno"
#define MSGTR_OSDunknown "sconosciuto"
#define MSGTR_OSDDVDNAV "DVDNAV: %s"
#define MSGTR_OSDChannel "Canale: %s"
#define MSGTR_OSDSubtitles "Sottotitoli: %si"
#define MSGTR_OSDSubtitlesOff "Sottotitoli: off"
#define MSGTR_OSDSubtitlesLanguage "Sottotitoli: (%d) %s"
#define MSGTR_OSDSub "Sottotitoli: (%d) %s%s"
#define MSGTR_OSDSubDelay "Ritardo sottotitoli: %d ms"
#define MSGTR_OSDSubPosition "Posizione sottotitoli: %d/100"
#define MSGTR_OSDSubAlignment "Allineamento sottotitoli: %s"
#define MSGTR_OSDAVDelay "Ritardo A-V: %d ms"
#define MSGTR_OSDSpeed "Velocit�: x %6.2f"
#define MSGTR_OSDStayOnTop "Resta in primo piano: %so"
#define MSGTR_OSDRootwin "Rootwin: %so"
#define MSGTR_OSDBorder "Bordo: %s"
#define MSGTR_OSDFramedrop "Scarto fotogrammi: %s"
#define MSGTR_OSDFramedropOn "on"
#define MSGTR_OSDFramedropHard "hard"
#define MSGTR_OSDFramedropOff "off"
#define MSGTR_OSDosd "OSD: %so"
#define MSGTR_OSDSubBottom "in basso"
#define MSGTR_OSDSubCenter "al centro"
#define MSGTR_OSDSubTop "in alto"

// mencoder.c:

#define MSGTR_UsingPass3ControllFile "Sto usando il file di controllo passo3: %s\n"
#define MSGTR_MissingFilename "\nNome file mancante.\n\n"
#define MSGTR_CannotOpenFile_Device "Impossibile aprire il file/dispositivo.\n"
#define MSGTR_CannotOpenDemuxer "Impossibile aprire il demuxer.\n"
#define MSGTR_NoAudioEncoderSelected "\nNessun encoder audio (-oac) scelto! Scegline uno (vedi -oac help) o -nosound.\n"
#define MSGTR_NoVideoEncoderSelected "\nNessun encoder video (-ovc) scelto! Selezionane uno (vedi -ovc help).\n"
#define MSGTR_CannotOpenOutputFile "Impossibile aprire il file di output '%s'.\n"
#define MSGTR_EncoderOpenFailed "Errore nell'apertura dell'encoder.\n"
#define MSGTR_MencoderWrongFormatAVI "\nATTENZIONE: IL FORMATO DEL FILE DI OUTPUT � _AVI_. vedi -of help.\n"
#define MSGTR_MencoderWrongFormatMPG "\nATTENZIONE: IL FORMATO DEL FILE DI OUTPUT � _MPEG_. vedi -of help.\n"
#define MSGTR_MissingOutputFilename "Nessun file di output specificato, per favore verifica l'opzione -o"
#define MSGTR_ForcingOutputFourcc "Forzo il fourcc di output a %x [%.4s]\n"
#define MSGTR_ForcingOutputAudiofmtTag "Forzo la tag del formato audio a 0x%x\n"
#define MSGTR_DuplicateFrames "\n%d fotogramma/i duplicato/i!!!    \n"
#define MSGTR_SkipFrame "\nScarto fotogramma!\n"
#define MSGTR_ResolutionDoesntMatch "\nIl nuovo file video ha diversa risoluzione o spazio colore dal precedente.\n"
#define MSGTR_FrameCopyFileMismatch "\nTutti i file video devono avere stessi fps, risoluz., e codec per -ovc copy.\n"
#define MSGTR_AudioCopyFileMismatch "\nTutti i file devono avere lo stesso codec audio e formato per -oac copy.\n"
#define MSGTR_NoAudioFileMismatch "\nImpossibile mescolare file solo audio con file video. Prova con -nosound.\n"
#define MSGTR_NoSpeedWithFrameCopy "WARNING: -speed non � detto che funzioni correttamente con -oac copy!\n"\
"L'encoding potrebbe essere danneggiato!\n"
#define MSGTR_ErrorWritingFile "%s: errore nella scrittura del file.\n"
#define MSGTR_RecommendedVideoBitrate "Il bitrate video consigliato per %s CD �: %d\n"
#define MSGTR_VideoStreamResult "\nFlusso video: %8.3f kbit/s  (%d B/s)  dim.: %d bytes  %5.3f sec   %d frames\n"
#define MSGTR_AudioStreamResult "\nFlusso audio: %8.3f kbit/s  (%d B/s)  dim.: %d bytes  %5.3f secondi\n"
#define MSGTR_OpenedStream "successo: formato: %d  dati: 0x%X - 0x%x\n"
#define MSGTR_VCodecFramecopy "videocodec: framecopy (%dx%d %dbpp fourcc=%x)\n"
#define MSGTR_ACodecFramecopy "audiocodec: framecopy (format=%x chans=%d rate=%d bits=%d B/s=%d sample-%d)\n"
#define MSGTR_CBRPCMAudioSelected "CBR PCM audio selezionato\n"
#define MSGTR_MP3AudioSelected "MP3 audio selezionato\n"
#define MSGTR_CannotAllocateBytes "Non posso allocare %d bytes\n"
#define MSGTR_SettingAudioDelay "Imposto il ritardo audio a %5.3f\n"
#define MSGTR_SettingVideoDelay "Imposto il ritardo video a %5.3f\n"
#define MSGTR_SettingAudioInputGain "Imposto il guadagno di ingresso audio a %f\n"
#define MSGTR_LamePresetEquals "\npreset=%s\n\n"
#define MSGTR_LimitingAudioPreload "Limito il preload audio a 0.4s\n"
#define MSGTR_IncreasingAudioDensity "Aumento la densit� audio a 4\n"
#define MSGTR_ZeroingAudioPreloadAndMaxPtsCorrection "Forzo il preload audio a 0, max pts correction a 0\n"
#define MSGTR_CBRAudioByterate "\n\nCBR audio: %d byte/sec, %d byte/blocco\n"
#define MSGTR_LameVersion "LAME versione %s (%s)\n\n"
#define MSGTR_InvalidBitrateForLamePreset ""\
"Errore: il bitrate specificato � fuori gamma per questo Preset\n"\
"\n"\
"Quando usi questo metodo devi usare un valore tra \"8\" e \"320\"\n"\
"\n"\
"Per altre informazioni usa: \"-lameopts preset=help\"\n"
#define MSGTR_InvalidLamePresetOptions ""\
"Errore: immesso un profilo e/o delle opzioni errate per questo Preset\n"\
"\n"\
"I profili disponibili sono:\n"\
"\n"\
"   <fast>        standard\n"\
"   <fast>        extreme\n"\
"                 insane\n"\
"   <cbr> (ABR Mode) - La modalit� ABR � implicita. Per usarla,\n"\
"                      specifica un bitrate. Per esempio:\n"\
"                      \"preset=185\" attiva questo\n"\
"                      preset e usa 185 come kbps medi.\n"\
"\n"\
"    Qualche esempio:\n"\
"\n"\
"    \"-lameopts fast:preset=standard  \"\n"\
" o  \"-lameopts  cbr:preset=192       \"\n"\
" o  \"-lameopts      preset=172       \"\n"\
" o  \"-lameopts      preset=extreme   \"\n"\
"\n"\
"Per altre informazioni usa: \"-lameopts preset=help\"\n"
#define MSGTR_LamePresetsLongInfo "\n"\
"I Presets sono costruiti in modo da dare la pi� alta qualit� possibile.\n"\
"\n"\
"Sono stati per la maggior parte sottosposti a test e rifiniti attraverso doppi\n"\
"test di ascolto per verificare e ottenere tale obiettivo.\n"\
"\n"\
"Vengono aggiornati continuamente per coincidere con gli ultimi sviluppi che\n"\
"ci sono e come risultato dovrebbero dare probabilmente la miglior qualit�\n"\
"attualmente possibile con LAME.\n"\
"\n"\
"Per attivare questi Presets:\n"\
"\n"\
"   Per le modalit� VBR (di solito qualit� pi� alta):\n"\
"\n"\
"     \"preset=standard\" Questo Preset di solito dovrebbe essere trasparente\n"\
"                             per molte persone per molta musica ed � gi�\n"\
"                             di qualit� piuttosto alta.\n"\
"\n"\
"     \"preset=extreme\"  Se hai una sensibilit� sonora buona e equivalente\n"\
"                             equipaggiamento, questo Preset avr� solitamente\n"\
"                             una qualit� un po' pi� alta della modalit�\n"\
"                             \"standard\".\n"\
"\n"\
"   Per modalit� CBR a 320kbps (la qualit� pi� alta possibile per i Presets):\n"\
"\n"\
"     \"preset=insane\"   Questo Preset dovrebbe essere decisamente buono\n"\
"                             per la maggior parte di persone e situazioni,\n"\
"                             ma se devi avere assoluta alta qualit� e nessun\n"\
"                             rispetto per la dimensione, devi usare questo.\n"\
"\n"\
"   Per modalit� ABR (alta qualit� per dato bitrate ma non alta come VBR):\n"\
"\n"\
"     \"preset=<kbps>\"   Usare questo Preset dar� solitamente buona qualit�\n"\
"                             a un dato bitrate. In dipendenza dal bitrate\n"\
"                             indicato, questo Preset determiner� ottimali\n"\
"                             impostazioni per quella particolare situazione.\n"\
"                             Anche se questo approccio funge, non � manco\n"\
"                             un po' flessibile come VBR, e di solito non d�"\
"                             la stessa qualit� del VBR a pi� alti bitrate.\n"\
"\n"\
"Le seguenti opzioni sono disponibili anche per i corrispondenti profili:\n"\
"\n"\
"   <fast>        standard\n"\
"   <fast>        extreme\n"\
"                 insane\n"\
"   <cbr> (Modalit� ABR) - La modalit� ABR � implicita. Per usarla,\n"\
"                   indicare semplicemente un bitrate. Per esempio:\n"\
"                   \"preset=185\" attiva questo Preset e viene\n"\
"                   usato 185 come media kbps.\n"\
"\n"\
"   \"fast\" - Abilita il nuovo VBR \"veloce\" per un dato profilo. Lo\n"\
"            svantaggio dell'alta velocit� � che spesso il bitrate\n"\
"            viene leggermente pi� alto rispetto alla modalit� normale\n"\
"            e la qualit� leggermente inferiore.\n"\
"   Attenzione: nell'attuale versione l'utilizzo di Preset \"veloce\" pu�\n"\
"            portare un bitrate troppo alto del normale.\n"\
"\n"\
"   \"cbr\"  - se usi la modalit� ABR (leggi sopra) con un certo bitrate\n"\
"            significativo come 80, 96, 112, 128, 160, 192, 224, 256, 320,\n"\
"            puoi usare l'opzione \"cbr\" per forzare l'encoding in modalit�\n"\
"            CBR al posto dello standard abr. ABR d� una pi� alta qualit�,\n"\
"            ma CBR torna utile in quelle situazioni dove ad esempio\n"\
"            trasmettere un mp3 su internet pu� essere importante.\n"\
"\n"\
"    Per esempio:\n"\
"\n"\
"    \"-lameopts fast:preset=standard  \"\n"\
" o  \"-lameopts  cbr:preset=192       \"\n"\
" o  \"-lameopts      preset=172       \"\n"\
" o  \"-lameopts      preset=extreme   \"\n"\
"\n"\
"\n"\
"Ci sono alcuni sinonimi per le modalit� ABR:\n"\
"phone => 16kbps/mono        phon+/lw/mw-eu/sw => 24kbps/mono\n"\
"mw-us => 40kbps/mono        voice => 56kbps/mono\n"\
"fm/radio/tape => 112kbps    hifi => 160kbps\n"\
"cd => 192kbps               studio => 256kbps"
#define MSGTR_LameCantInit ""\
"Non posso impostare le opzioni di LAME, controlla bitrate/samplerate,\n"\
"per bitrate molto bassi (<32) servono minori samplerate (es. -srate 8000).\n"\
"Se ogni altra cosa non funziona, prova un Preset."
#define MSGTR_ConfigfileError "errore file di configurazione"
#define MSGTR_ErrorParsingCommandLine "errore leggendo la riga comando"
#define MSGTR_VideoStreamRequired "Il flusso video � obbligatorio!\n"
#define MSGTR_ForcingInputFPS "i fps saranno interpretati come %5.2f\n"
#define MSGTR_RawvideoDoesNotSupportAudio "Il formato output RAWVIDEO non supporta l'audio - lo disabilito\n"
#define MSGTR_DemuxerDoesntSupportNosound "Questo demuxer non supporta ancora -nosound.\n"
#define MSGTR_MemAllocFailed "Allocazione memoria non riuscita\n"
#define MSGTR_NoMatchingFilter "Non trovo il filtro/il formato ao corrispondente!\n"
#define MSGTR_MP3WaveFormatSizeNot30 "sizeof(MPEGLAYER3WAVEFORMAT)==%d!=30, compilatore C bacato?\n"
#define MSGTR_NoLavcAudioCodecName "Audio LAVC, Manca il nome del codec!\n"
#define MSGTR_LavcAudioCodecNotFound "Audio LAVC, Non trovo l'encoder per il codec %s\n"
#define MSGTR_CouldntAllocateLavcContext "Audio LAVC, non posso allocare il contesto!\n"
#define MSGTR_CouldntOpenCodec "Non posso aprire il codec %s, br=%d\n"
#define MSGTR_CantCopyAudioFormat "Il formato audio 0x%x � incompatibile con '-oac copy', prova invece '-oac pcm' o usa '-fafmttag' per forzare.\n"

// cfg-mencoder.h:

#define MSGTR_MEncoderMP3LameHelp "\n\n"\
" vbr=<0-4>     metodo bitrate variabile\n"\
"                0: cbr\n"\
"                1: mt\n"\
"                2: rh(default)\n"\
"                3: abr\n"\
"                4: mtrh\n"\
"\n"\
" abr           bitrate medio\n"\
"\n"\
" cbr           bitrate costante\n"\
"               Forza il metodo CBR anche sui successivi Preset ABR\n"\
"\n"\
" br=<0-1024>   specifica il bitrate in kBit (solo CBR e ABR)\n"\
"\n"\
" q=<0-9>       qualit� (0-massima, 9-minima) (solo per VBR)\n"\
"\n"\
" aq=<0-9>      qualit� algoritmo (0-migliore/pi� lento, 9-peggiore/pi� veloce)\n"\
"\n"\
" ratio=<1-100> rapporto di compressione\n"\
"\n"\
" vol=<0-10>    imposta il guadagno dell'ingresso audio\n"\
"\n"\
" mode=<0-3>    (default: auto)\n"\
"                0: stereo\n"\
"                1: joint-stereo\n"\
"                2: due canali indipendenti\n"\
"                3: mono\n"\
"\n"\
" padding=<0-2>\n"\
"                0: no\n"\
"                1: tutto\n"\
"                2: regola\n"\
"\n"\
" fast          attiva la codifica pi� veloce sui successivi preset VBR,\n"\
"               qualit� leggermente inferiore ai bitrate pi� alti.\n"\
"\n"\
" preset=<value> fornisce le migliori impostazioni possibili di qualit�.\n"\
"                 medium: codifica VBR, buona qualit�\n"\
"                 (intervallo bitrate 150-180 kbps)\n"\
"                 standard:  codifica VBR, qualit� alta\n"\
"                 (intervallo bitrate 170-210 kbps)\n"\
"                 extreme: codifica VBR, qualit� molto alta\n"\
"                 (intervallo bitrate 200-240 kbps)\n"\
"                 insane:  codifica CBR, massima qualit� via preset\n"\
"                 (bitrate 320 kbps)\n"\
"                 <8-320>: codifica ABR con bitrate medio impostato in kbps.\n\n"

//codec-cfg.c:
#define MSGTR_DuplicateFourcc "FourCC duplicato"
#define MSGTR_TooManyFourccs "troppi FourCCs/formati..."
#define MSGTR_ParseError "errore lettura"
#define MSGTR_ParseErrorFIDNotNumber "errore lettura (ID formato non � un numero?)"
#define MSGTR_ParseErrorFIDAliasNotNumber "errore lettura (l'alias ID formato not � un numero?)"
#define MSGTR_DuplicateFID "ID formato duplicato"
#define MSGTR_TooManyOut "troppi out..."
#define MSGTR_InvalidCodecName "\nnome codec(%s) non valido!\n"
#define MSGTR_CodecLacksFourcc "\nil codec(%s) non ha FourCC/formato!\n"
#define MSGTR_CodecLacksDriver "\nil codec(%s) non ha un driver!\n"
#define MSGTR_CodecNeedsDLL "\nil codec(%s) abbisogna di una 'dll'!\n"
#define MSGTR_CodecNeedsOutfmt "\nil codec(%s) abbisogna di un 'outfmt'!\n"
#define MSGTR_CantAllocateComment "Non riesco ad allocare memoria per il commento."
#define MSGTR_GetTokenMaxNotLessThanMAX_NR_TOKEN "get_token(): max >= MAX_MR_TOKEN!"
#define MSGTR_ReadingFile "Leggo %s: "
#define MSGTR_CantOpenFileError "Non posso aprire '%s': %s\n"
#define MSGTR_CantGetMemoryForLine "Non posso aver la memoria per 'line': %s\n"
#define MSGTR_CantReallocCodecsp "Non posso riallocare '*codecsp': %s\n"
#define MSGTR_CodecNameNotUnique "Il nome codec '%s' non � univoco."
#define MSGTR_CantStrdupName "Non posso far strdup -> 'name': %s\n"
#define MSGTR_CantStrdupInfo "Non posso far strdup -> 'info': %s\n"
#define MSGTR_CantStrdupDriver "Non posso far strdup -> 'driver': %s\n"
#define MSGTR_CantStrdupDLL "Non posso far strdup -> 'dll': %s"
#define MSGTR_AudioVideoCodecTotals "%d audio & %d video codecs\n"
#define MSGTR_CodecDefinitionIncorrect "Il codec non � correttamente definito."
#define MSGTR_OutdatedCodecsConf "Il codecs.conf � troppo vecchio/incompatibile con questa versione di MPlayer!"

// divx4_vbr.c:
#define MSGTR_OutOfMemory "Memoria esaurita"
#define MSGTR_OverridingTooLowBitrate "Il bitrate specificato � troppo basso per questo filmato.\n"\
"Il bitrate minimo possibile � %.0f kbps. Ignoro il valore dato dall'utente\n"

// fifo.c
#define MSGTR_CannotMakePipe "Non posso costruire una PIPE!\n"

// m_config.c
#define MSGTR_SaveSlotTooOld "Trovati troppi slot vecchi salvati da lvl %d: %d !!!\n"
#define MSGTR_InvalidCfgfileOption "L'opzione %s non pu� essere usata nel file di configurazione.\n"
#define MSGTR_InvalidCmdlineOption "L'opzione %s non pu� essere usata da riga comando.\n"
#define MSGTR_InvalidSuboption "Errore: l'opzione '%s' non ha la subopzione '%s'.\n"
#define MSGTR_MissingSuboptionParameter "Errore: la subopzione '%s' di '%s' deve avere un parametro!\n"
#define MSGTR_MissingOptionParameter "Errore: l'opzione '%s' deve avere un parametro!\n"
#define MSGTR_OptionListHeader "\n Nome                 Tipo            Min        Max      Global  CL    Cfg\n\n"
#define MSGTR_TotalOptions "\nTotale: %d opzioni\n"
#define MSGTR_TooDeepProfileInclusion "ATTENZIONE: Livello di inclusione troppo profondo nel profilo.\n"
#define MSGTR_NoProfileDefined "Non � stato definito alcun profilo.\n"
#define MSGTR_AvailableProfiles "Profili disponibili:\n"
#define MSGTR_UnknownProfile "Profilo '%s' sconosciuto.\n"
#define MSGTR_Profile "Profilo %s: %s\n"

// open.c, stream.c:
#define MSGTR_CdDevNotfound "Dispositivo CD-ROM '%s' non trovato!\n"
#define MSGTR_ErrTrackSelect "Errore nella selezione della traccia del VCD!"
#define MSGTR_ReadSTDIN "Leggo da stdin...\n"
#define MSGTR_UnableOpenURL "Impossibile aprire l'URL: %s\n"
#define MSGTR_ConnToServer "Connesso al server: %s\n"
#define MSGTR_FileNotFound "File non trovato: '%s'\n"

#define MSGTR_SMBInitError "Impossibile inizializzare la libreria libsmbclient: %d\n"
#define MSGTR_SMBFileNotFound "Impossibile aprire dalla rete: '%s'\n"
#define MSGTR_SMBNotCompiled "MPlayer non � stato compilato con supporto di lettura da SMB.\n"

#define MSGTR_CantOpenDVD "Impossibile aprire il dispositivo DVD: %s\n"
#define MSGTR_NoDVDSupport "MPlayer � stato compilato senza il supporto per DVD, esco\n" 
#define MSGTR_DVDwait "Leggo la struttura del disco, per favore aspetta...\n"
#define MSGTR_DVDnumTitles "Ci sono %d titolo/i su questo DVD.\n"
#define MSGTR_DVDinvalidTitle "Numero del titolo del DVD non valido: %d\n"
#define MSGTR_DVDnumChapters "Ci sono %d capitolo/i in questo titolo del DVD.\n"
#define MSGTR_DVDinvalidChapter "Numero del capitolo del DVD non valido: %d\n"
#define MSGTR_DVDinvalidChapterRange "Intervallo dei capitoli indicato non valido: %s\n"
#define MSGTR_DVDinvalidLastChapter "Numero del capitolo finale del DVD non valido: %d\n"
#define MSGTR_DVDnumAngles "Ci sono %d angolazione/i in questo titolo del DVD.\n"
#define MSGTR_DVDinvalidAngle "Numero delle angolazioni del DVD non valido: %d\n"
#define MSGTR_DVDnoIFO "Impossibile aprire il file IFO per il titolo del DVD %d.\n"
#define MSGTR_DVDnoVMG "Impossibile aprire le informazioni VMG!\n"
#define MSGTR_DVDnoVOBs "Impossibile aprire il VOB del titolo (VTS_%02d_1.VOB).\n"
#define MSGTR_DVDnoMatchingAudio "Non trovata la lingua dell'audio DVD corrispondente!\n"
#define MSGTR_DVDaudioChannel "Scelto canale audio DVD: %d lingua: %c%c\n" 
#define MSGTR_DVDnoMatchingSubtitle "Non trovata la lingua dei sottotitoli DVD corrispondente!\n"
#define MSGTR_DVDsubtitleChannel "Scelto canale sottotitoli DVD: %d lingua: %c%c\n"
#define MSGTR_DVDopenOk "DVD aperto con successo.\n"

// muxer.c, muxer_*.c:
#define MSGTR_TooManyStreams "Troppi flussi!"
#define MSGTR_RawMuxerOnlyOneStream "Il muxer rawaudio supporta solo un flusso audio!\n"
#define MSGTR_IgnoringVideoStream "Ignoro il flusso video!\n"
#define MSGTR_UnknownStreamType "Attenzione! Tipo flusso sconosciuto: %d\n"
#define MSGTR_WarningLenIsntDivisible "Attenzione! len non � divisibile per samplesize!\n"
// TODO: muxer frame buffer ???
#define MSGTR_MuxbufMallocErr "Il buffer fotogrammi del muxer non pu� allocare la memoria!\n"
#define MSGTR_MuxbufReallocErr "Il buffer fotogrammi del muxer non pu� riallocare la memoria!\n"
#define MSGTR_MuxbufSending "Il buffer fotogrammi del muxer sta inviando %d fotogramma/i al muxer.\n"
#define MSGTR_WritingHeader "Scrittura intestazione in corso...\n"
#define MSGTR_WritingTrailer "Scrittura indice in corso...\n"

// demuxer.c, demux_*.c:
#define MSGTR_AudioStreamRedefined "Avvertimento! Intestazione del flusso audio %d ridefinito!\n"
#define MSGTR_VideoStreamRedefined "Avvertimento! Intestazione del flusso video %d ridefinito!\n"
#define MSGTR_TooManyAudioInBuffer "\nDEMUXER: Troppi (%d in %d byte) pacchetti audio nel buffer!\n"
#define MSGTR_TooManyVideoInBuffer "\nDEMUXER: Troppi (%d in %d byte) pacchetti video nel buffer!\n"
#define MSGTR_MaybeNI "Forse stai riproducendo un flusso/file non-interleaved o il codec non funziona?\n" \
          "Per i file .AVI, prova a forzare la modalit� 'non-interleaved' con l'opz. -ni.\n"
#define MSGTR_SwitchToNi "\nRilevato file .AVI con interleave errato - passo alla modalit� -ni!\n"
#define MSGTR_Detected_XXX_FileFormat "Rilevato formato file %s!\n"
#define MSGTR_DetectedAudiofile "Rilevato file audio!\n"
#define MSGTR_NotSystemStream "il formato non � 'MPEG System Stream'... (forse � 'Transport Stream'?)\n"
#define MSGTR_InvalidMPEGES "Flusso MPEG-ES non valido??? Contatta l'autore, pu� essere un baco :(\n"
#define MSGTR_FormatNotRecognized "===== Mi dispiace, questo formato file non � riconosciuto/supportato ======\n"\
				  "=== Se questo � un file AVI, ASF o MPEG, per favore contatta l'autore! ===\n"
#define MSGTR_MissingVideoStream "Nessun flusso video trovato!\n"
#define MSGTR_MissingAudioStream "Nessun flusso audio trovato -> nessun suono\n"
#define MSGTR_MissingVideoStreamBug "Manca il flusso video!? Contatta l'autore, pu� essere un baco :(\n"

#define MSGTR_DoesntContainSelectedStream "demux: il file non contiene il flusso audio o video selezionato\n"

#define MSGTR_NI_Forced "Forzato"
#define MSGTR_NI_Detected "Rilevato"
#define MSGTR_NI_Message "%s formato file AVI NON-INTERLEAVED!\n"

#define MSGTR_UsingNINI "Uso di formato file AVI NON-INTERLEAVED corrotto.\n"
#define MSGTR_CouldntDetFNo "Impossibile determinare il numero di fotogrammi (per lo spostamento assoluto).\n"
#define MSGTR_CantSeekRawAVI "Impossibile spostarsi nei flussi .AVI grezzi. (richiesto un indice, prova con l'opzione -idx.)\n"
#define MSGTR_CantSeekFile "Impossibile spostarsi in questo file!  \n"

#define MSGTR_EncryptedVOB "File VOB criptato! Leggi il file DOCS/HTML/en/cd-dvd.html.\n"

#define MSGTR_MOVcomprhdr "MOV: Il supporto delle intestazioni compresse richiede ZLIB!\n"
#define MSGTR_MOVvariableFourCC "MOV: Avvertimento! Rilevato FOURCC variabile!?\n"
#define MSGTR_MOVtooManyTrk "MOV: Avvertimento! troppe tracce!"
#define MSGTR_FoundAudioStream "==> Trovato flusso audio: %d\n"
#define MSGTR_FoundVideoStream "==> Trovato flusso video: %d\n"
#define MSGTR_DetectedTV "Ho trovato una TV! ;-)\n"
#define MSGTR_ErrorOpeningOGGDemuxer "Impossibile aprire il demuxer ogg\n"
#define MSGTR_ASFSearchingForAudioStream "ASF: sto cercando il flusso audio (id:%d)\n"
#define MSGTR_CannotOpenAudioStream "Impossibile aprire il flusso audio: %s\n"
#define MSGTR_CannotOpenSubtitlesStream "Impossibile aprire il flusso dei sottotitoli: %s\n"
#define MSGTR_OpeningAudioDemuxerFailed "Errore nell'apertura del demuxer audio: %s\n"
#define MSGTR_OpeningSubtitlesDemuxerFailed "Errore nell'apertura del demuxer dei sottotitoli: %s\n"
#define MSGTR_TVInputNotSeekable "Impossibile spostarsi in un programma TV!\n"\
"(Probabilmente lo spostamento sar� usato per cambiare canale ;)\n"
#define MSGTR_DemuxerInfoAlreadyPresent "Info demuxer %s gi� presente!\n"
#define MSGTR_ClipInfo "Informazioni filmato: \n"

#define MSGTR_LeaveTelecineMode "\ndemux_mpg: Rilevato formato NTSC 30000/1001fps, cambio framerate.\n"
#define MSGTR_EnterTelecineMode "\ndemux_mpg: Rilevato formato NTSC 24000/1001fps progressivo, cambio framerate.\n"

#define MSGTR_CacheFill "\rRiempio cache: %5.2f%% (%"PRId64" byte)   " 
#define MSGTR_NoBindFound "Nessun controllo legato al tasto '%s'"
#define MSGTR_FailedToOpen "Apertura di '%s' fallita\n"
							       //
// dec_video.c & dec_audio.c:
#define MSGTR_CantOpenCodec "impossibile aprire il codec\n"
#define MSGTR_CantCloseCodec "impossibile chiudere il codec\n"

#define MSGTR_MissingDLLcodec "ERRORE: Impossibile aprire il codec DirectShow richiesto: %s\n"
#define MSGTR_ACMiniterror "Impossibile caricare/inizializz. il codec AUDIO Win32/ACM (manca il file DLL?)\n"
#define MSGTR_MissingLAVCcodec "Impossibile trovare il codec '%s' in libavcodec...\n"

#define MSGTR_MpegNoSequHdr "MPEG: FATAL: EOF mentre cercavo la sequenza di intestazione\n"
#define MSGTR_CannotReadMpegSequHdr "FATAL: Impossibile leggere la sequenza di intestazione!\n"
#define MSGTR_CannotReadMpegSequHdrEx "FATAL: Impossibile leggere l'estensione della sequenza di intestazione!\n"
#define MSGTR_BadMpegSequHdr "MPEG: Sequenza di intestazione non valida!\n"
#define MSGTR_BadMpegSequHdrEx "MPEG: Estensione della sequenza di intestazione non valida!\n"

#define MSGTR_ShMemAllocFail "Impossibile allocare la memoria condivisa\n"
#define MSGTR_CantAllocAudioBuf "Impossibile allocare il buffer di uscita dell'audio\n"

#define MSGTR_UnknownAudio "Formato audio sconosciuto/mancante, non uso l'audio\n"

#define MSGTR_UsingExternalPP "[PP] Utilizzo un filtro di postprocessing esterno, max q = %d\n"
#define MSGTR_UsingCodecPP "[PP] Utilizzo il postprocessing del codec, max q = %d\n"
#define MSGTR_VideoAttributeNotSupportedByVO_VD "L'attributo video '%s' non � supportato dal vo & vd selezionati! \n"
#define MSGTR_VideoCodecFamilyNotAvailableStr "Famiglia di codec video voluta [%s] (vfm=%s) non disponibile.\nAbilitala in compilazione.\n"
#define MSGTR_AudioCodecFamilyNotAvailableStr "Famiglia di codec audio voluta [%s] (afm=%s) non disponibile.\nAbilitala in compilazione.\n"
#define MSGTR_OpeningVideoDecoder "Apertura decoder video: [%s] %s\n"
#define MSGTR_SelectedVideoCodec "Scelto codec video: [%s] vfm: %s (%s)\n"
#define MSGTR_OpeningAudioDecoder "Apertura decoder audio: [%s] %s\n"
#define MSGTR_SelectedAudioCodec "Scelto codec audio: [%s] afm: %s (%s)\n"
#define MSGTR_BuildingAudioFilterChain "Costruisco catena filtri audio per %dHz/%dch/%s -> %dHz/%dch/%s...\n"
#define MSGTR_UninitVideoStr "uninit video: %s  \n"
#define MSGTR_UninitAudioStr "uninit audio: %s  \n"
#define MSGTR_VDecoderInitFailed "Inizializzazione VDecoder fallita :(\n"
#define MSGTR_ADecoderInitFailed "Inizializzazione ADecoder fallita :(\n"
#define MSGTR_ADecoderPreinitFailed "Preinizializzazione ADecoder fallita :(\n"
#define MSGTR_AllocatingBytesForInputBuffer "dec_audio: Alloco %d byte per il buffer di input\n"
#define MSGTR_AllocatingBytesForOutputBuffer "dec_audio: Alloco %d + %d = %d byte per il buffer di output\n"

// LIRC:
#define MSGTR_SettingUpLIRC "Configurazione del supporto per LIRC...\n"
#define MSGTR_LIRCdisabled "Non potrai usare il tuo telecomando\n"
#define MSGTR_LIRCopenfailed "Apertura del supporto per LIRC fallita!\n"
#define MSGTR_LIRCcfgerr "Fallimento nella lettura del file di configurazione di LIRC %s!\n"

// vf.c
#define MSGTR_CouldNotFindVideoFilter "Impossibile trovare il filtro video '%s'\n"
#define MSGTR_CouldNotOpenVideoFilter "Impossibile aprire il filtro video '%s'\n"
#define MSGTR_OpeningVideoFilter "Apertura filtro video: "
#define MSGTR_CannotFindColorspace "Impossibile trovare uno spazio colore in comune, anche inserendo 'scale' :(\n"

// vd.c
#define MSGTR_CodecDidNotSet "VDec: Il codec non ha impostato sh->disp_w and sh->disp_h, tento di risolvere.\n"
#define MSGTR_VoConfigRequest "VDec: configurazione chiesta dal vo - %d x %d (sp.col. preferito: %s)\n"
#define MSGTR_CouldNotFindColorspace "Impossibile trovare uno spazio colore adatto - riprovo con -vf scale...\n"
#define MSGTR_MovieAspectIsSet "Movie-Aspect � %.2f:1 - riscalo per ottenere un rapporto corretto.\n"
#define MSGTR_MovieAspectUndefined "Movie-Aspect non definito - nessuna scalatura.\n"

// vd_dshow.c, vd_dmo.c
#define MSGTR_DownloadCodecPackage "Devi installare o aggiornare i codec binari.\nVai a http://mplayerhq.hu/homepage/dload.html\n"
#define MSGTR_DShowInitOK "INFO: Win32/DShow inizializzato correttamente.\n"
#define MSGTR_DMOInitOK "INFO: Win32/DMO inizializzato correttamente.\n"

// x11_common.c
#define MSGTR_EwmhFullscreenStateFailed "\nX11: Impossibile inviare l'evento schermo pieno EWMH!\n"
#define MSGTR_CouldNotFindXScreenSaver "xscreensaver_disable: Non riesco a trovare la finestra di XScreenSaver.\n" 
#define MSGTR_SelectedVideoMode "XF86VM: Scelta modalit� video %dx%d per la dimensione immagine %dx%d.\n"

#define MSGTR_InsertingAfVolume "[Mixer] Nessun mixer hardware, filtro volume inserito automaticamente.\n"
#define MSGTR_NoVolume "[Mixer] Nessuna regolazione di volume disponibile.\n"

// ====================== GUI messages/buttons ========================

#ifdef HAVE_NEW_GUI

// --- labels ---
#define MSGTR_About "Informazioni su"
#define MSGTR_FileSelect "Seleziona il file..."
#define MSGTR_SubtitleSelect "Seleziona il sottotitolo..."
#define MSGTR_OtherSelect "Seleziona..."
#define MSGTR_AudioFileSelect "Seleziona canale audio esterno..."
#define MSGTR_FontSelect "Seleziona il carattere..."
#define MSGTR_PlayList "PlayList"
#define MSGTR_Equalizer "Equalizzatore"			 
#define MSGTR_SkinBrowser "Gestore Skin"
#define MSGTR_Network "Flusso dati dalla rete..."
#define MSGTR_Preferences "Preferenze"
#define MSGTR_AudioPreferences "Configurazione driver audio"
#define MSGTR_NoMediaOpened "nessun media aperto"
#define MSGTR_VCDTrack "Traccia VCD %d"
#define MSGTR_NoChapter "nessun capitolo"
#define MSGTR_Chapter "capitolo %d"
#define MSGTR_NoFileLoaded "nessun file caricato"
			 
// --- buttons ---
#define MSGTR_Ok "Ok"
#define MSGTR_Cancel "Annulla"
#define MSGTR_Add "Aggiungi"
#define MSGTR_Remove "Rimuovi"
#define MSGTR_Clear "Pulisci"
#define MSGTR_Config "Configura"
#define MSGTR_ConfigDriver "Configura driver"
#define MSGTR_Browse "Sfoglia"

// --- error messages ---
#define MSGTR_NEMDB "Mi dispiace, non c'� sufficiente memoria per il buffer di disegno."
#define MSGTR_NEMFMR "Mi dispiace, non c'� sufficiente memoria per visualizzare il menu."
#define MSGTR_IDFGCVD "Mi dispiace, non ho trovato un driver di output video compatibile con la GUI."
#define MSGTR_NEEDLAVCFAME "Mi dispiace, non puoi riprodurre file non-MPEG con il tuo dispositivo DXR3/H+\nsenza ricodificarli.\nAbilita lavc o fame nella finestra di configurazione DXR3/H+."
#define MSGTR_UNKNOWNWINDOWTYPE "Trovato tipo finestra sconosciuto..."

// --- skin loader error messages
#define MSGTR_SKIN_ERRORMESSAGE "[skin] errore nel file di configurazione della skin alla riga %d: %s"
#define MSGTR_SKIN_WARNING1 "[skin] avvertimento nel file di configurazione della skin alla riga %d:\nwidget trovato ma non trovata prima la \"section\" (%s)"
#define MSGTR_SKIN_WARNING2 "[skin] avvertimento nel file di configurazione della skin alla riga %d:\nwidget trovato ma non trovata prima la \"subsection\" (%s)"
#define MSGTR_SKIN_WARNING3 "[skin] avvertimento nel file di configurazione della skin alla riga %d:\nquesta sottosezione non � supportata dal widget (%s)"
#define MSGTR_SKIN_SkinFileNotFound "[skin] file ( %s ) non trovato.\n"
#define MSGTR_SKIN_SkinFileNotReadable "[skin] file ( %s ) non leggibile.\n"
#define MSGTR_SKIN_BITMAP_16bit  "bitmap con profondit� di 16 bit o inferiore non supportata (%s).\n"
#define MSGTR_SKIN_BITMAP_FileNotFound  "file non trovato (%s)\n"
#define MSGTR_SKIN_BITMAP_BMPReadError "BMP, errore di lettura (%s)\n"
#define MSGTR_SKIN_BITMAP_TGAReadError "TGA, errore di lettura (%s)\n"
#define MSGTR_SKIN_BITMAP_PNGReadError "PNG, errore di lettura (%s)\n"
#define MSGTR_SKIN_BITMAP_RLENotSupported "RLE packed TGA non supportato (%s)\n"
#define MSGTR_SKIN_BITMAP_UnknownFileType "tipo di file sconosciuto (%s)\n"
#define MSGTR_SKIN_BITMAP_ConvertError "errore nella conversione da 24 bit a 32 bit (%s)\n"
#define MSGTR_SKIN_BITMAP_UnknownMessage "messaggio sconosciuto: %s\n"
#define MSGTR_SKIN_FONT_NotEnoughtMemory "memoria insufficiente\n"
#define MSGTR_SKIN_FONT_TooManyFontsDeclared "dichiarati troppi font\n"
#define MSGTR_SKIN_FONT_FontFileNotFound "file dei font non trovato\n"
#define MSGTR_SKIN_FONT_FontImageNotFound "file delle immagini dei font non trovato\n"
#define MSGTR_SKIN_FONT_NonExistentFontID "identificatore del font inesistente (%s)\n"
#define MSGTR_SKIN_UnknownParameter "parametro sconosciuto  (%s)\n"
#define MSGTR_SKIN_SKINCFG_SkinNotFound "Skin non trovata (%s).\n"
#define MSGTR_SKIN_SKINCFG_SelectedSkinNotFound "Skin scelta ( %s ) not trovata, provo con la 'default'...\n"
#define MSGTR_SKIN_SKINCFG_SkinCfgReadError "Errore nella lettura del file di configurazione della skin (%s).\n"
#define MSGTR_SKIN_LABEL "Skins:"

// --- gtk menus
#define MSGTR_MENU_AboutMPlayer "Informazioni su MPlayer"
#define MSGTR_MENU_Open "Apri..."
#define MSGTR_MENU_PlayFile "Riproduci il file..."
#define MSGTR_MENU_PlayVCD "Riproduci il VCD..."
#define MSGTR_MENU_PlayDVD "Riproduci il DVD..."
#define MSGTR_MENU_PlayURL "Riproduci l'URL..."
#define MSGTR_MENU_LoadSubtitle "Carica i sottotitoli..."
#define MSGTR_MENU_DropSubtitle "Elimina i sototitoli..."
#define MSGTR_MENU_LoadExternAudioFile "Carica file audio esterni..."
#define MSGTR_MENU_Playing "Riproduzione"
#define MSGTR_MENU_Play "Riproduci"
#define MSGTR_MENU_Pause "Pausa"
#define MSGTR_MENU_Stop "Interrompi"
#define MSGTR_MENU_NextStream "Stream successivo"
#define MSGTR_MENU_PrevStream "Stream precedente"
#define MSGTR_MENU_Size "Dimensione"
#define MSGTR_MENU_HalfSize   "Dimensione dimezzata"
#define MSGTR_MENU_NormalSize "Dimensione normale"
#define MSGTR_MENU_DoubleSize "Dimensione doppia"
#define MSGTR_MENU_FullScreen "Schermo intero"
#define MSGTR_MENU_DVD "DVD"
#define MSGTR_MENU_VCD "VCD"
#define MSGTR_MENU_PlayDisc "Disco in riproduzione..."
#define MSGTR_MENU_ShowDVDMenu "Mostra il menu del DVD"
#define MSGTR_MENU_Titles "Titoli"
#define MSGTR_MENU_Title "Titolo %2d"
#define MSGTR_MENU_None "(niente)"
#define MSGTR_MENU_Chapters "Capitoli"
#define MSGTR_MENU_Chapter "Capitolo %2d"
#define MSGTR_MENU_AudioLanguages "Lingua dell'audio"
#define MSGTR_MENU_SubtitleLanguages "Lingua dei sottotitoli"
#define MSGTR_MENU_PlayList MSGTR_PlayList
#define MSGTR_MENU_SkinBrowser "Ricerca skin"
#define MSGTR_MENU_Preferences MSGTR_Preferences
#define MSGTR_MENU_Exit "Uscita..."
#define MSGTR_MENU_Mute "Muto"
#define MSGTR_MENU_Original "Originale"
#define MSGTR_MENU_AspectRatio "Aspetto"
#define MSGTR_MENU_AudioTrack "Traccia audio"
#define MSGTR_MENU_Track "Traccia %d"
#define MSGTR_MENU_VideoTrack "Traccia video"

// --- equalizer
// Note: If you change MSGTR_EQU_Audio please see if it still fits MSGTR_PREFERENCES_Audio
#define MSGTR_EQU_Audio "Audio"
// Note: If you change MSGTR_EQU_Video please see if it still fits MSGTR_PREFERENCES_Video
#define MSGTR_EQU_Video "Video"
#define MSGTR_EQU_Contrast "Contrasto: "
#define MSGTR_EQU_Brightness "Luminosit�: "
#define MSGTR_EQU_Hue "Tonalit�: "
#define MSGTR_EQU_Saturation "Saturazione: "
#define MSGTR_EQU_Front_Left "Anteriore Sinistro"
#define MSGTR_EQU_Front_Right "Anteriore Destro"
#define MSGTR_EQU_Back_Left "Posteriore Sinistro"
#define MSGTR_EQU_Back_Right "Posteriore Destro"
#define MSGTR_EQU_Center "Centro"
#define MSGTR_EQU_Bass "Bassi"
#define MSGTR_EQU_All "Tutti"
#define MSGTR_EQU_Channel1 "Canale 1:"
#define MSGTR_EQU_Channel2 "Canale 2:"
#define MSGTR_EQU_Channel3 "Canale 3:"
#define MSGTR_EQU_Channel4 "Canale 4:"
#define MSGTR_EQU_Channel5 "Canale 5:"
#define MSGTR_EQU_Channel6 "Canale 6:"

// --- playlist
#define MSGTR_PLAYLIST_Path "Percorso"
#define MSGTR_PLAYLIST_Selected "File selezionati"
#define MSGTR_PLAYLIST_Files "File"
#define MSGTR_PLAYLIST_DirectoryTree "albero delle directory"

// --- preferences
#define MSGTR_PREFERENCES_Audio MSGTR_EQU_Audio
#define MSGTR_PREFERENCES_Video MSGTR_EQU_Video
#define MSGTR_PREFERENCES_Misc "Varie"
#define MSGTR_PREFERENCES_None "Nessuno"
#define MSGTR_PREFERENCES_DriverDefault "Driver predefinito"
#define MSGTR_PREFERENCES_AvailableDrivers "Driver disponibili:"
#define MSGTR_PREFERENCES_DoNotPlaySound "Non riprodurre l'audio"
#define MSGTR_PREFERENCES_NormalizeSound "Normalizza l'audio"
#define MSGTR_PREFERENCES_EnEqualizer "Abilita l'equalizzatore"
#define MSGTR_PREFERENCES_SoftwareMixer "Abilita Mixer Software"
#define MSGTR_PREFERENCES_ExtraStereo "Abilita l'extra stereo"
#define MSGTR_PREFERENCES_Coefficient "Coefficiente:"
#define MSGTR_PREFERENCES_AudioDelay "Ritardo audio"
#define MSGTR_PREFERENCES_DoubleBuffer "Abilita il doppio buffering"
#define MSGTR_PREFERENCES_DirectRender "Abilita il direct rendering"
#define MSGTR_PREFERENCES_FrameDrop "Abilita lo scarto dei frame"
#define MSGTR_PREFERENCES_HFrameDrop "Abilita lo scarto HARD (forte) dei frame (pericoloso)"
#define MSGTR_PREFERENCES_Flip "Ribalta l'immagine sottosopra"
#define MSGTR_PREFERENCES_Panscan "Panscan: "
#define MSGTR_PREFERENCES_OSDTimer "Timer e indicatori"
#define MSGTR_PREFERENCES_OSDTimerPercentageTotalTime "Timer, percentuale e tempo totale"
#define MSGTR_PREFERENCES_OSDProgress "Solo progressbars"
#define MSGTR_PREFERENCES_Subtitle "Sottotitolo:"
#define MSGTR_PREFERENCES_SUB_Delay "Ritardo: "
#define MSGTR_PREFERENCES_SUB_FPS "FPS:"
#define MSGTR_PREFERENCES_SUB_POS "Posizione: "
#define MSGTR_PREFERENCES_SUB_AutoLoad "Disattiva il caricamento automatico dei sottotitoli"
#define MSGTR_PREFERENCES_SUB_Unicode "Sottotitoli unicode"
#define MSGTR_PREFERENCES_SUB_MPSUB "Converti i sottotitoli nel formato sottotitolo di MPlayer"
#define MSGTR_PREFERENCES_SUB_SRT "Converti i sottotitoli nel formato SubViewer (SRT) basato sul tempo"
#define MSGTR_PREFERENCES_SUB_Overlap "Attiva/Disattiva sovrapposizione sottotitoli"
#define MSGTR_PREFERENCES_Font "Carattere:"
#define MSGTR_PREFERENCES_Codecs "Codec e demuxer"
#define MSGTR_PREFERENCES_FontFactor "Font factor:"
#define MSGTR_PREFERENCES_PostProcess "Abilita postprocessing"
#define MSGTR_PREFERENCES_AutoQuality "Qualit� automatica: "
#define MSGTR_PREFERENCES_NI "Utilizza un analizzatore non-interleaved per i file AVI"
#define MSGTR_PREFERENCES_IDX "Ricostruisci l'indice, se necessario"
#define MSGTR_PREFERENCES_VideoCodecFamily "Famiglia codec video:"
#define MSGTR_PREFERENCES_AudioCodecFamily "Famiglia codec audio:"
#define MSGTR_PREFERENCES_FRAME_OSD_Level "Livello OSD"
#define MSGTR_PREFERENCES_FRAME_Subtitle "Sottotitoli"
#define MSGTR_PREFERENCES_FRAME_Font "Carattere"
#define MSGTR_PREFERENCES_FRAME_PostProcess "Postprocessing"
#define MSGTR_PREFERENCES_FRAME_CodecDemuxer "Codec e demuxer"
#define MSGTR_PREFERENCES_FRAME_Cache "Cache"
#define MSGTR_PREFERENCES_FRAME_Misc MSGTR_PREFERENCES_Misc
#define MSGTR_PREFERENCES_Audio_Device "Dispositivo:"
#define MSGTR_PREFERENCES_Audio_Mixer "Mixer:"
#define MSGTR_PREFERENCES_Audio_MixerChannel "Canale mixer:"
#define MSGTR_PREFERENCES_Message "Ricorda che devi riavviare la riproduzione affinch� alcune opzioni abbiano effetto!"
#define MSGTR_PREFERENCES_DXR3_VENC "Video encoder:"
#define MSGTR_PREFERENCES_DXR3_LAVC "Usa LAVC (FFmpeg)"
#define MSGTR_PREFERENCES_DXR3_FAME "Usa FAME"
#define MSGTR_PREFERENCES_FontEncoding1 "Unicode"
#define MSGTR_PREFERENCES_FontEncoding2 "Western European Languages (ISO-8859-1)"
#define MSGTR_PREFERENCES_FontEncoding3 "Western European Languages with Euro (ISO-8859-15)"
#define MSGTR_PREFERENCES_FontEncoding4 "Slavic/Central European Languages (ISO-8859-2)"
#define MSGTR_PREFERENCES_FontEncoding5 "Esperanto, Galician, Maltese, Turkish (ISO-8859-3)"
#define MSGTR_PREFERENCES_FontEncoding6 "Old Baltic charset (ISO-8859-4)"
#define MSGTR_PREFERENCES_FontEncoding7 "Cyrillic (ISO-8859-5)"
#define MSGTR_PREFERENCES_FontEncoding8 "Arabic (ISO-8859-6)"
#define MSGTR_PREFERENCES_FontEncoding9 "Modern Greek (ISO-8859-7)"
#define MSGTR_PREFERENCES_FontEncoding10 "Turkish (ISO-8859-9)"
#define MSGTR_PREFERENCES_FontEncoding11 "Baltic (ISO-8859-13)"
#define MSGTR_PREFERENCES_FontEncoding12 "Celtic (ISO-8859-14)"
#define MSGTR_PREFERENCES_FontEncoding13 "Hebrew charsets (ISO-8859-8)"
#define MSGTR_PREFERENCES_FontEncoding14 "Russian (KOI8-R)"
#define MSGTR_PREFERENCES_FontEncoding15 "Ukrainian, Belarusian (KOI8-U/RU)"
#define MSGTR_PREFERENCES_FontEncoding16 "Simplified Chinese charset (CP936)"
#define MSGTR_PREFERENCES_FontEncoding17 "Traditional Chinese charset (BIG5)"
#define MSGTR_PREFERENCES_FontEncoding18 "Japanese charsets (SHIFT-JIS)"
#define MSGTR_PREFERENCES_FontEncoding19 "Korean charset (CP949)"
#define MSGTR_PREFERENCES_FontEncoding20 "Thai charset (CP874)"
#define MSGTR_PREFERENCES_FontEncoding21 "Cyrillic Windows (CP1251)"
#define MSGTR_PREFERENCES_FontEncoding22 "Slavic/Central European Windows (CP1250)"
#define MSGTR_PREFERENCES_FontNoAutoScale "No autoscale"
#define MSGTR_PREFERENCES_FontPropWidth "Proporzionale alla larghezza del filmato"
#define MSGTR_PREFERENCES_FontPropHeight "Proporzionale all'altezza del filmato"
#define MSGTR_PREFERENCES_FontPropDiagonal "Proporzionale alla diagonale del filmato"
#define MSGTR_PREFERENCES_FontEncoding "Codifica:"
#define MSGTR_PREFERENCES_FontBlur "Blur:"
#define MSGTR_PREFERENCES_FontOutLine "Outline:"
#define MSGTR_PREFERENCES_FontTextScale "Text scale:"
#define MSGTR_PREFERENCES_FontOSDScale "Scala OSD:"
#define MSGTR_PREFERENCES_SubtitleOSD "Sottotitoli & OSD"
#define MSGTR_PREFERENCES_Cache "Cache on/off"
#define MSGTR_PREFERENCES_LoadFullscreen "Avvia a pieno schermo"
#define MSGTR_PREFERENCES_CacheSize "Dimensione cache: "
#define MSGTR_PREFERENCES_SaveWinPos "Salva la posizione della finestra"
#define MSGTR_PREFERENCES_XSCREENSAVER "Arresta XScreenSaver"
#define MSGTR_PREFERENCES_PlayBar "Attiva playbar"
#define MSGTR_PREFERENCES_AutoSync "AutoSync on/off"
#define MSGTR_PREFERENCES_AutoSyncValue "Autosync: "
#define MSGTR_PREFERENCES_CDROMDevice "Dispositivo CD-ROM:"
#define MSGTR_PREFERENCES_DVDDevice "Dispositivo DVD:"
#define MSGTR_PREFERENCES_FPS "FPS del filmato:"
#define MSGTR_PREFERENCES_ShowVideoWindow "Mostra la finestra video anche quando non � attiva"
#define MSGTR_PREFERENCES_ArtsBroken "Le nuove versioni di aRts sono incompatibili "\
           "con GTK 1.x e GMPlayer crasher�!"

#define MSGTR_ABOUT_UHU "Lo sviluppo della GUI � sponsorizzato da UHU Linux\n"
#define MSGTR_ABOUT_Contributors "Contributori codice e documentazione\n"
#define MSGTR_ABOUT_Codecs_libs_contributions "Codec e librerie di terze parti\n"
#define MSGTR_ABOUT_Translations "Traduzioni\n"
#define MSGTR_ABOUT_Skins "Skin\n"

// --- messagebox
#define MSGTR_MSGBOX_LABEL_FatalError "Errore fatale!"
#define MSGTR_MSGBOX_LABEL_Error "Errore!"
#define MSGTR_MSGBOX_LABEL_Warning "Avvertimento!"

// bitmap.c

#define MSGTR_NotEnoughMemoryC32To1 "[c32to1] non c'� abbastanza memoria per l'immagine\n"
#define MSGTR_NotEnoughMemoryC1To32 "[c1to32] non c'� abbastanza memoria per l'immagine\n"

// cfg.c

#define MSGTR_ConfigFileReadError "[cfg] errore di lettura file di configurazione...\n"
#define MSGTR_UnableToSaveOption "[cfg] non riesco a salvare l'opzione '%s'.\n"

// interface.c

#define MSGTR_DeletingSubtitles "[GUI] Elimino sottotitoli.\n"
#define MSGTR_LoadingSubtitles "[GUI] Carico sottotitoli: %s\n"
#define MSGTR_AddingVideoFilter "[GUI] Aggiungo filtro video: %s\n"
#define MSGTR_RemovingVideoFilter "[GUI] Rimuovo filtro video: %s\n"

// mw.c

#define MSGTR_NotAFile "Questo non pare essere un file: %s !\n"

// ws.c

#define MSGTR_WS_CouldNotOpenDisplay "[ws] Non posso aprire il display.\n"
#define MSGTR_WS_RemoteDisplay "[ws] Display remoto, disabilito XMITSHM.\n"
#define MSGTR_WS_NoXshm "[ws] Spiacente, il tuo sistema non supporta l'estensione 'X shared memory'.\n"
#define MSGTR_WS_NoXshape "[ws] Spiacente, il tuo sistema non supporta l'estensione XShape.\n"
#define MSGTR_WS_ColorDepthTooLow "[ws] Spiacente, la profondit� colore � troppo bassa.\n"
#define MSGTR_WS_TooManyOpenWindows "[ws] Ci sono troppe finestre aperte.\n"
#define MSGTR_WS_ShmError "[ws] errore estensione 'shared memory'\n"
#define MSGTR_WS_NotEnoughMemoryDrawBuffer "[ws] Spiacente, non abbastanza memoria per il buffer di disegno.\n"
#define MSGTR_WS_DpmsUnavailable "DPMS non disponibile?\n"
#define MSGTR_WS_DpmsNotEnabled "Non posso abilitare DPMS.\n"

// wsxdnd.c

#define MSGTR_WS_NotAFile "Questo non sembra essere un file...\n"
#define MSGTR_WS_DDNothing "D&D: Nessun valore di ritorno!\n"

#endif

// ======================= VO Video Output drivers ========================

#define MSGTR_VOincompCodec "Il dispositivo di uscita video_out scelto � incompatibile con questo codec.\n"\
                "Prova aggiungendo il filtro scale, per esempio -vf spp,scale invece di -vf spp.\n"
#define MSGTR_VO_GenericError "E' accaduto questo errore"
#define MSGTR_VO_UnableToAccess "Impossibile accedere a"
#define MSGTR_VO_ExistsButNoDirectory "gi� esiste, ma non � una directory."
#define MSGTR_VO_DirExistsButNotWritable "La directory di output esiste gi�, ma non � scrivibile."
#define MSGTR_VO_DirExistsAndIsWritable "La directory di output esiste gi� ed � scrivibile."
#define MSGTR_VO_CantCreateDirectory "Non posso creare la directory di output."
#define MSGTR_VO_CantCreateFile "Non posso creare il file di output."
#define MSGTR_VO_DirectoryCreateSuccess "Directory di output creata con successo."
#define MSGTR_VO_ParsingSuboptions "Leggo subopzioni."
#define MSGTR_VO_SuboptionsParsedOK "Lettura subopzioni OK."
#define MSGTR_VO_ValueOutOfRange "Valore fuori gamma"
#define MSGTR_VO_NoValueSpecified "Nessun valore specificato."
#define MSGTR_VO_UnknownSuboptions "Subopzione/i sconosciuta/e"

// vo_aa.c

#define MSGTR_VO_AA_HelpHeader "\n\nEcco le subopzioni per l'aalib vo_aa:\n"
#define MSGTR_VO_AA_AdditionalOptions "Le opzioni addizionali di vo_aa:\n" \
"  help        mostra questo messaggio\n" \
"  osdcolor    imposta colore osd\n" \
"  subcolor    imposta colore sottotitoli\n" \
"        i colori possibili sono:\n"\
"           0 : normal\n" \
"           1 : dim\n" \
"           2 : bold\n" \
"           3 : boldfont\n" \
"           4 : reverse\n" \
"           5 : special\n\n\n"

// vo_jpeg.c
#define MSGTR_VO_JPEG_ProgressiveJPEG "Progressive JPEG abilitata."
#define MSGTR_VO_JPEG_NoProgressiveJPEG "Progressive JPEG disabilitata."
#define MSGTR_VO_JPEG_BaselineJPEG "Baseline JPEG abilitata."
#define MSGTR_VO_JPEG_NoBaselineJPEG "Baseline JPEG disabilitata."

// vo_pnm.c
#define MSGTR_VO_PNM_ASCIIMode "Modalit� ASCII abilitata."
#define MSGTR_VO_PNM_RawMode "Modalit� Raw abilitata."
#define MSGTR_VO_PNM_PPMType "Scriver� files PPM."
#define MSGTR_VO_PNM_PGMType "Scriver� files PGM."
#define MSGTR_VO_PNM_PGMYUVType "Scriver� files PGMYUV."

// vo_yuv4mpeg.c
#define MSGTR_VO_YUV4MPEG_InterlacedHeightDivisibleBy4 "La modalit� interlacciata richiede l'altezza immagine divisibile per 4."
#define MSGTR_VO_YUV4MPEG_InterlacedLineBufAllocFail "Impossibile allocare il buffer di linea per la modalit� interlacciata." 
#define MSGTR_VO_YUV4MPEG_InterlacedInputNotRGB "L'input non � RGB, non posso separare la crominanza per campi!"
#define MSGTR_VO_YUV4MPEG_WidthDivisibleBy2 "La larghezza immagine dev'essere divisibile per 2."
#define MSGTR_VO_YUV4MPEG_NoMemRGBFrameBuf "Non c'� abbastanza memoria per allocare il framebuffer RGB."
#define MSGTR_VO_YUV4MPEG_OutFileOpenError "Non posso allocare memoria o spazio per scrivere \"%s\"!"
#define MSGTR_VO_YUV4MPEG_OutFileWriteError "Errore di scrittura dell'immagine in uscita!"
#define MSGTR_VO_YUV4MPEG_UnknownSubDev "Subdispositivo sconosciuto: %s"
// 'top-field first'/'bottom-field first' should be left as they are written,
// since there's a reference to these in the man page
#define MSGTR_VO_YUV4MPEG_InterlacedTFFMode "Uso modalit� di uscita interlacciata, top-field first."
#define MSGTR_VO_YUV4MPEG_InterlacedBFFMode "Uso modalit� di uscita interlacciata, bottom-field first."
#define MSGTR_VO_YUV4MPEG_ProgressiveMode "Uso la modalit� fotogramma progressivo (default)."

// sub.c
#define MSGTR_VO_SUB_Seekbar "Barra ricerca"
#define MSGTR_VO_SUB_Play "Riproduci"
#define MSGTR_VO_SUB_Pause "Pausa"
#define MSGTR_VO_SUB_Stop "Stop"
#define MSGTR_VO_SUB_Rewind "Indietro"
#define MSGTR_VO_SUB_Forward "Avanti"
#define MSGTR_VO_SUB_Clock "Orologio"
#define MSGTR_VO_SUB_Contrast "Contrasto"
#define MSGTR_VO_SUB_Saturation "Saturazione"
#define MSGTR_VO_SUB_Volume "Volume"
#define MSGTR_VO_SUB_Brightness "Luminosit�"
#define MSGTR_VO_SUB_Hue "Tonalit�"

// vo_xv.c
#define MSGTR_VO_XV_ImagedimTooHigh "Dimensioni dell'immagine origine troppo grandi: %ux%u (il massimo � %ux%u)\n"

// Old vo drivers that have been replaced

#define MSGTR_VO_PGM_HasBeenReplaced "Il driver di uscita video pgm � stato sostituito con -vo pnm:pgmyuv.\n"
#define MSGTR_VO_MD5_HasBeenReplaced "Il driver di uscita video md5 � stato sostituito con -vo md5sum.\n"

// ======================= AO Audio Output drivers ========================

// libao2 

// audio_out.c
#define MSGTR_AO_ALSA9_1x_Removed "audio_out: i moduli alsa9/alsa1x sono stati rimossi, ora usa -ao alsa.\n"

// ao_oss.c
#define MSGTR_AO_OSS_CantOpenMixer "[AO OSS] audio_setup: Non posso aprire il dispositivo mixer %s: %s\n"
#define MSGTR_AO_OSS_ChanNotFound "[AO OSS] audio_setup: Il mixer scheda audio non ha il canale '%s' uso default.\n"
#define MSGTR_AO_OSS_CantOpenDev "[AO OSS] audio_setup: Non posso aprire il dispositivo audio %s: %s\n"
#define MSGTR_AO_OSS_CantMakeFd "[AO OSS] audio_setup: Non riesco a bloccare il dispositivo: %s\n"
#define MSGTR_AO_OSS_CantSet "[AO OSS] Non posso impostare il device audio %s a %s output, provo %s...\n"
#define MSGTR_AO_OSS_CantSetChans "[AO OSS] audio_setup: Fallita impostazione audio a %d canali.\n"
#define MSGTR_AO_OSS_CantUseGetospace "[AO OSS] audio_setup: il driver non supporta SNDCTL_DSP_GETOSPACE :-(\n"
#define MSGTR_AO_OSS_CantUseSelect "[AO OSS]\n   ***  Il tuo driver audio NON supporta select()  ***\n Ricompila MPlayer con #undef HAVE_AUDIO_SELECT in config.h !\n\n"
#define MSGTR_AO_OSS_CantReopen "[AO OSS]\nErrore fatale: *** NON POSSO RIAPRIRE / RESETTARE IL DEVICE AUDIO *** %s\n"

// ao_arts.c
#define MSGTR_AO_ARTS_CantInit "[AO ARTS] %s\n"
#define MSGTR_AO_ARTS_ServerConnect "[AO ARTS] Connesso al server del suono.\n"
#define MSGTR_AO_ARTS_CantOpenStream "[AO ARTS] Non posso apire un flusso.\n"
#define MSGTR_AO_ARTS_StreamOpen "[AO ARTS] Flusso aperto.\n"
#define MSGTR_AO_ARTS_BufferSize "[AO ARTS] dimensione buffer: %d\n"

// ao_dxr2.c
#define MSGTR_AO_DXR2_SetVolFailed "[AO DXR2] Impostazione del volume a %d fallita.\n"
#define MSGTR_AO_DXR2_UnsupSamplerate "[AO DXR2] %d Hz non supportati, prova a ricampionare (resample).\n"

// ao_esd.c
#define MSGTR_AO_ESD_CantOpenSound "[AO ESD] esd_open_sound fallito: %s\n"
#define MSGTR_AO_ESD_LatencyInfo "[AO ESD] latenza: [server: %0.2fs, net: %0.2fs] (scarto %0.2fs)\n"
#define MSGTR_AO_ESD_CantOpenPBStream "[AO ESD] fallimento nell'aprire il flusso di riproduzione ESD: %s\n"

// ao_mpegpes.c
#define MSGTR_AO_MPEGPES_CantSetMixer "[AO MPEGPES] Impostazione mixer DVB fallita: %s.\n" 
#define MSGTR_AO_MPEGPES_UnsupSamplerate "[AO MPEGPES] %d Hz non supportati, prova a ricampionare (resample).\n"

// ao_pcm.c
#define MSGTR_AO_PCM_FileInfo "[AO PCM] File: %s (%s)\nPCM: Samplerate: %iHz Canali: %s Formato %s\n"
#define MSGTR_AO_PCM_HintInfo "[AO PCM] Info: Un dump pi� veloce si ottiene con -vc null -vo null\n[AO PCM] Info: Per scrivere file WAVE usa -ao pcm:waveheader (default).\n"
#define MSGTR_AO_PCM_CantOpenOutputFile "[AO PCM] Non posso aprire %s in scrittura!\n"

// ao_sdl.c
#define MSGTR_AO_SDL_INFO "[AO SDL] Samplerate: %iHz Canali: %s Formato %s\n"
#define MSGTR_AO_SDL_DriverInfo "[AO SDL] Uso il driver audio %s.\n"
#define MSGTR_AO_SDL_UnsupportedAudioFmt "[AO SDL] Formato audio non supportato: 0x%x.\n"
#define MSGTR_AO_SDL_CantInit "[AO SDL] Inizializzazione del SDL fallita: %s\n"
#define MSGTR_AO_SDL_CantOpenAudio "[AO SDL] Non posso aprire l'audio: %s\n"

// ao_sgi.c
#define MSGTR_AO_SGI_INFO "[AO SGI] control.\n"
#define MSGTR_AO_SGI_InitInfo "[AO SGI] init: Samplerate: %iHz Canali: %s Formato %s\n"
#define MSGTR_AO_SGI_InvalidDevice "[AO SGI] play: dispositivo non valido.\n"
#define MSGTR_AO_SGI_CantSetParms_Samplerate "[AO SGI] init: setparams fallito: %s\nNon posso impostare il samplerate voluto.\n"
#define MSGTR_AO_SGI_CantSetAlRate "[AO SGI] init: AL_RATE non � stato accettato dalla risorsa.\n"
#define MSGTR_AO_SGI_CantGetParms "[AO SGI] init: getparams fallito: %s\n"
#define MSGTR_AO_SGI_SampleRateInfo "[AO SGI] init: il samplerate ora � %lf (la frequenza voluta � %lf)\n"
#define MSGTR_AO_SGI_InitConfigError "[AO SGI] init: %s\n"
#define MSGTR_AO_SGI_InitOpenAudioFailed "[AO SGI] init: Non posso apire il canale audio: %s\n"
#define MSGTR_AO_SGI_Uninit "[AO SGI] uninit: ...\n"
#define MSGTR_AO_SGI_Reset "[AO SGI] reset: ...\n"
#define MSGTR_AO_SGI_PauseInfo "[AO SGI] audio_pause: ...\n"
#define MSGTR_AO_SGI_ResumeInfo "[AO SGI] audio_resume: ...\n"

// ao_sun.c
#define MSGTR_AO_SUN_RtscSetinfoFailed "[AO SUN] rtsc: SETINFO fallito.\n"
#define MSGTR_AO_SUN_RtscWriteFailed "[AO SUN] rtsc: scrittura fallita."
#define MSGTR_AO_SUN_CantOpenAudioDev "[AO SUN] Non posso aprire il dispositivo audio %s, %s  -> no audio.\n"
#define MSGTR_AO_SUN_UnsupSampleRate "[AO SUN] audio_setup: la tua scheda non supporta il canale %d, %s, %d Hz samplerate.\n"
#define MSGTR_AO_SUN_CantUseSelect "[AO SUN]\n   ***  Il tuo driver audio NON supporta select()  ***\n Ricompila MPlayer con #undef HAVE_AUDIO_SELECT in config.h !\n\n"
#define MSGTR_AO_SUN_CantReopenReset "[AO SUN]\nErrore fatale: *** NON POSSO RIAPRIRE / RESETTARE IL DEVICE AUDIO *** %s\n"

// ao_alsa5.c
#define MSGTR_AO_ALSA5_InitInfo "[AO ALSA5] alsa-init: formato richiesto: %d Hz, %d canali, %s\n"
#define MSGTR_AO_ALSA5_SoundCardNotFound "[AO ALSA5] alsa-init: nessuna scheda audio trovata.\n"
#define MSGTR_AO_ALSA5_InvalidFormatReq "[AO ALSA5] alsa-init: formato voluto (%s) invalido - output disabilitato.\n"
#define MSGTR_AO_ALSA5_PlayBackError "[AO ALSA5] alsa-init: errore apertura riproduzione: %s\n"
#define MSGTR_AO_ALSA5_PcmInfoError "[AO ALSA5] alsa-init: errore informazioni pcm: %s\n"
#define MSGTR_AO_ALSA5_SoundcardsFound "[AO ALSA5] alsa-init: %d scheda/e audio travata/e, uso: %s\n"
#define MSGTR_AO_ALSA5_PcmChanInfoError "[AO ALSA5] alsa-init: errore informazioni canale pcm: %s\n"
#define MSGTR_AO_ALSA5_CantSetParms "[AO ALSA5] alsa-init: errore impostazione parametri: %s\n"
#define MSGTR_AO_ALSA5_CantSetChan "[AO ALSA5] alsa-init: errore nell'impostazione canale: %s\n"
#define MSGTR_AO_ALSA5_ChanPrepareError "[AO ALSA5] alsa-init: preparazione del canale: %s\n"
#define MSGTR_AO_ALSA5_DrainError "[AO ALSA5] alsa-uninit: errore 'drain' riproduzione: %s\n"
#define MSGTR_AO_ALSA5_FlushError "[AO ALSA5] alsa-uninit: errore 'flush' riproduzione: %s\n"
#define MSGTR_AO_ALSA5_PcmCloseError "[AO ALSA5] alsa-uninit: errore chiusura pcm: %s\n"
#define MSGTR_AO_ALSA5_ResetDrainError "[AO ALSA5] alsa-reset: errore 'drain' riproduzione: %s\n"
#define MSGTR_AO_ALSA5_ResetFlushError "[AO ALSA5] alsa-reset: errore 'flush' riproduzione: %s\n"
#define MSGTR_AO_ALSA5_ResetChanPrepareError "[AO ALSA5] alsa-reset: errore preparazione canale: %s\n"
#define MSGTR_AO_ALSA5_PauseDrainError "[AO ALSA5] alsa-pause: errore 'drain' riproduzione: %s\n"
#define MSGTR_AO_ALSA5_PauseFlushError "[AO ALSA5] alsa-pause: errore 'flush' riproduzione: %s\n"
#define MSGTR_AO_ALSA5_ResumePrepareError "[AO ALSA5] alsa-resume: errore preparazione canale: %s\n"
#define MSGTR_AO_ALSA5_Underrun "[AO ALSA5] alsa-play: ritardo alsa, reimposto il flusso.\n"
#define MSGTR_AO_ALSA5_PlaybackPrepareError "[AO ALSA5] alsa-play: errore preparazione riproduzione: %s\n"
#define MSGTR_AO_ALSA5_WriteErrorAfterReset "[AO ALSA5] alsa-play: errore di scrittura dopo reset: %s - mi arrendo.\n"
#define MSGTR_AO_ALSA5_OutPutError "[AO ALSA5] alsa-play: errore di output: %s\n"

// ao_plugin.c

#define MSGTR_AO_PLUGIN_InvalidPlugin "[AO PLUGIN] plugin non valido: %s\n"

// ======================= AF Audio Filters ================================

// libaf 

// af_ladspa.c

#define MSGTR_AF_LADSPA_AvailableLabels "etichette disponibili in"
#define MSGTR_AF_LADSPA_WarnNoInputs "WARNING! Questo plugin LADSPA non ha entrate audio.\n  Il segnale audio in entrata verr� perso."
#define MSGTR_AF_LADSPA_ErrMultiChannel "I plugin multi-canale (>2) non sono supportati (finora).\n  Usare solo i plugin mono e stereo."
#define MSGTR_AF_LADSPA_ErrNoOutputs "Questo plugin LADSPA non ha uscite audio."
#define MSGTR_AF_LADSPA_ErrInOutDiff "Il numero delle entrate e uscite audio del plugin LADSPA differiscono."
#define MSGTR_AF_LADSPA_ErrFailedToLoad "fallimento nel caricare"
#define MSGTR_AF_LADSPA_ErrNoDescriptor "Non trovo la funzione ladspa_descriptor() nella libreria indicata."
#define MSGTR_AF_LADSPA_ErrLabelNotFound "Non trovo l'etichetta nella libreria plugin."
#define MSGTR_AF_LADSPA_ErrNoSuboptions "Nessuna subopzione  indicata"
#define MSGTR_AF_LADSPA_ErrNoLibFile "Nessuna libreria indicata"
#define MSGTR_AF_LADSPA_ErrNoLabel "Nessuna etichetta di filtro indicata"
#define MSGTR_AF_LADSPA_ErrNotEnoughControls "Non sono stati indicati abbastaza controlli sulla riga comando"
#define MSGTR_AF_LADSPA_ErrControlBelow "%s: Il controllo di input #%d � sotto il limite inferiore di %0.4f.\n"
#define MSGTR_AF_LADSPA_ErrControlAbove "%s: Il controllo di input #%d � sopra al limite superiore di %0.4f.\n"

// ========================== INPUT =========================================

// joystick.c

#define MSGTR_INPUT_JOYSTICK_Opening "Apertura dispositivo joystick %s\n"
#define MSGTR_INPUT_JOYSTICK_CantOpen "Non posso aprire il dispositivo joystick %s: %s\n"
#define MSGTR_INPUT_JOYSTICK_ErrReading "Errore in lettura dispositivo joystick: %s\n"
#define MSGTR_INPUT_JOYSTICK_LoosingBytes "Joystick: persi %d byte di dati\n"
#define MSGTR_INPUT_JOYSTICK_WarnLostSync "Joystick: Evento di attenzione in inizializzazione, persa sincronia col driver\n"
#define MSGTR_INPUT_JOYSTICK_WarnUnknownEvent "Joystick: Avviso: tipo di evento %d sconosciuto\n"

// input.c

#define MSGTR_INPUT_INPUT_ErrCantRegister2ManyCmdFds "Troppi descrittori comandi, non posso registrare il descrittore %d.\n"
#define MSGTR_INPUT_INPUT_ErrCantRegister2ManyKeyFds "Troppi descrittori tasti, non posso registrare il descrittore %d.\n"
#define MSGTR_INPUT_INPUT_ErrArgMustBeInt "Comando %s: l'argomento %d non � un intero.\n"
#define MSGTR_INPUT_INPUT_ErrArgMustBeFloat "Comando %s: l'argomento %d non � un decimale.\n"
#define MSGTR_INPUT_INPUT_ErrUnterminatedArg "Comando %s: l'argomento %d � indeterminato.\n"
#define MSGTR_INPUT_INPUT_ErrUnknownArg "Argomento %d sconosciuto\n"
#define MSGTR_INPUT_INPUT_Err2FewArgs "Il comando %s richiede almeno %d argomenti, trovati solo %d finora.\n"
#define MSGTR_INPUT_INPUT_ErrReadingCmdFd "Errore in lettura descrittore comandi %d: %s\n"
#define MSGTR_INPUT_INPUT_ErrCmdBufferFullDroppingContent "Il buffer cmd del descrittore %d � pieno: ne scarto il contenuto\n"
#define MSGTR_INPUT_INPUT_ErrInvalidCommandForKey "Controllo non valido legato al tasto '%s'"
#define MSGTR_INPUT_INPUT_ErrSelect "Errore selezione: %s\n"
#define MSGTR_INPUT_INPUT_ErrOnKeyInFd "Errore nel descrittore input tasto %d\n"
#define MSGTR_INPUT_INPUT_ErrDeadKeyOnFd "Input da tasto morto nel descrittore %d\n"
#define MSGTR_INPUT_INPUT_Err2ManyKeyDowns "Troppi eventi di 'tasto premuto' contemporaneamente\n"
#define MSGTR_INPUT_INPUT_ErrOnCmdFd "Errore nel descrittore comando %d\n"
#define MSGTR_INPUT_INPUT_ErrReadingInputConfig "Fallimento nella lettura del file di configurazione dell'input %s: %s\n"
#define MSGTR_INPUT_INPUT_ErrUnknownKey "Il tasto '%s' � sconosciuto\n"
#define MSGTR_INPUT_INPUT_ErrUnfinishedBinding "Legame %s non completato\n"
#define MSGTR_INPUT_INPUT_ErrBuffer2SmallForKeyName "Il buffer � troppo piccolo per questo nome tasto: %s\n"
#define MSGTR_INPUT_INPUT_ErrNoCmdForKey "Nessun comando trovato per il tasto %s"
#define MSGTR_INPUT_INPUT_ErrBuffer2SmallForCmd "Il buffer � troppo piccolo per il comando %s\n"
#define MSGTR_INPUT_INPUT_ErrWhyHere "Cosa ci stiamo facendo qui?\n"
#define MSGTR_INPUT_INPUT_ErrCantInitJoystick "Impossibile inizializzare i controlli del joystick\n"
#define MSGTR_INPUT_INPUT_ErrCantStatFile "Impossibile fare stat di %s: %s\n"
#define MSGTR_INPUT_INPUT_ErrCantOpenFile "Impossibile aprire %s: %s\n"

// ========================== LIBMPDEMUX ===================================

// url.c

#define MSGTR_MPDEMUX_URL_StringAlreadyEscaped "La stringa sembra essere gi� filtrata in url_escape %c%c1%c2\n"

// ai_alsa1x.c

#define MSGTR_MPDEMUX_AIALSA1X_CannotSetSamplerate "Non posso impostare il samplerate\n"
#define MSGTR_MPDEMUX_AIALSA1X_CannotSetBufferTime "Non posso impostare il tempo del buffer\n"
#define MSGTR_MPDEMUX_AIALSA1X_CannotSetPeriodTime "Non posso impostare il tempo del periodo\n"

// ai_alsa1x.c / ai_alsa.c

#define MSGTR_MPDEMUX_AIALSA_PcmBrokenConfig "Configurazione PCM rovinata: nessuna configurazione disponibile\n"
#define MSGTR_MPDEMUX_AIALSA_UnavailableAccessType "Tipo di accesso non disponibile\n"
#define MSGTR_MPDEMUX_AIALSA_UnavailableSampleFmt "Formato sample non disponibile\n"
#define MSGTR_MPDEMUX_AIALSA_UnavailableChanCount "Calcolo canali non disponibile - reimposto al default: %d\n"
#define MSGTR_MPDEMUX_AIALSA_CannotInstallHWParams "Impossibile impostare i parametri hardware: %s\n"
#define MSGTR_MPDEMUX_AIALSA_PeriodEqualsBufferSize "Non posso usare il periodo uguale al buffer (%u == %lu)\n"
#define MSGTR_MPDEMUX_AIALSA_CannotInstallSWParams "Impossibile impostare i parametri software: %s\n"
#define MSGTR_MPDEMUX_AIALSA_ErrorOpeningAudio "Non posso aprire l'audio: %s\n"
#define MSGTR_MPDEMUX_AIALSA_AlsaStatusError "ALSA Errore di stato: %s"
#define MSGTR_MPDEMUX_AIALSA_AlsaXRUN "ALSA xrun!!! (almeno di %.3f ms)\n"
#define MSGTR_MPDEMUX_AIALSA_AlsaStatus "ALSA Stato:\n"
#define MSGTR_MPDEMUX_AIALSA_AlsaXRUNPrepareError "ALSA xrun: errore preparazione: %s"
#define MSGTR_MPDEMUX_AIALSA_AlsaReadWriteError "ALSA errore di lettura/scrittura"

// ai_oss.c

#define MSGTR_MPDEMUX_AIOSS_Unable2SetChanCount "Impossibile impostare il numero di canali: %d\n"
#define MSGTR_MPDEMUX_AIOSS_Unable2SetStereo "Impossibile impostare lo stereo: %d\n"
#define MSGTR_MPDEMUX_AIOSS_Unable2Open "Non posso aprire '%s': %s\n"
#define MSGTR_MPDEMUX_AIOSS_UnsupportedFmt "Formato non supportato\n"
#define MSGTR_MPDEMUX_AIOSS_Unable2SetAudioFmt "Impossibile impostare il formato audio."
#define MSGTR_MPDEMUX_AIOSS_Unable2SetSamplerate "Impossibile impostare il samplerate: %d\n"
#define MSGTR_MPDEMUX_AIOSS_Unable2SetTrigger "Impossibile impostare il trigger: %d\n"
#define MSGTR_MPDEMUX_AIOSS_Unable2GetBlockSize "Non posso ricavare la dimensione del blocco!\n"
#define MSGTR_MPDEMUX_AIOSS_AudioBlockSizeZero "La dimensione del blocco audio � zero, la imposto a %d!\n"
#define MSGTR_MPDEMUX_AIOSS_AudioBlockSize2Low "La dimensione del blocco audio � troppo bassa, la imposto a %d!\n"

// asfheader.c

#define MSGTR_MPDEMUX_ASFHDR_HeaderSizeOver1MB "FATALE: la dimensione dell'intestazione � pi� grande di 1 MB (%d)!\nPerfavore contatta gli autori di MPlayer e invia/rendi disponibile questo file.\n"
#define MSGTR_MPDEMUX_ASFHDR_HeaderMallocFailed "Non ho potuto allocare %d byte per l'intestazione\n"
#define MSGTR_MPDEMUX_ASFHDR_EOFWhileReadingHeader "EOF durante la lettura dell'intestazione asf, file danneggiato/incompleto?\n"
#define MSGTR_MPDEMUX_ASFHDR_DVRWantsLibavformat "DVR funzioner� probabilmente solo con libavformat, prova -demuxer 35 se hai problemi\n"
#define MSGTR_MPDEMUX_ASFHDR_NoDataChunkAfterHeader "Nessun dato trovato dopo l'intestazione!\n"
#define MSGTR_MPDEMUX_ASFHDR_AudioVideoHeaderNotFound "ASF: nessuna intestazione audio o video trovata - file danneggiato?\n"
#define MSGTR_MPDEMUX_ASFHDR_InvalidLengthInASFHeader "Lunghezza non valida nell'intestazione ASF!\n"

// asf_mmst_streaming.c

#define MSGTR_MPDEMUX_MMST_WriteError "errore di scrittura\n"
#define MSGTR_MPDEMUX_MMST_EOFAlert "\nattenzione! eof\n"
#define MSGTR_MPDEMUX_MMST_PreHeaderReadFailed "lettura pre-intestazione fallita\n"
#define MSGTR_MPDEMUX_MMST_InvalidHeaderSize "Dimensione intestazione non valida, mi arrendo\n"
#define MSGTR_MPDEMUX_MMST_HeaderDataReadFailed "lettura dati intestazione fallita\n"
#define MSGTR_MPDEMUX_MMST_packet_lenReadFailed "lettura packet_len fallita\n"
#define MSGTR_MPDEMUX_MMST_InvalidRTSPPacketSize "Dimensione pacchetto rtsp invalida, mi arrendo\n"
#define MSGTR_MPDEMUX_MMST_CmdDataReadFailed "lettura dati comando fallita\n"
#define MSGTR_MPDEMUX_MMST_HeaderObject "oggetto intestazione\n"
#define MSGTR_MPDEMUX_MMST_DataObject "oggetto dati\n"
#define MSGTR_MPDEMUX_MMST_FileObjectPacketLen "oggetto file, lunghezza pacchetto (packet length) = %d (%d)\n"
#define MSGTR_MPDEMUX_MMST_StreamObjectStreamID "oggetto flusso, id flusso: %d\n"
#define MSGTR_MPDEMUX_MMST_2ManyStreamID "troppi id, flusso scartato"
#define MSGTR_MPDEMUX_MMST_UnknownObject "oggetto sconosciuto\n"
#define MSGTR_MPDEMUX_MMST_MediaDataReadFailed "lettura dati contenuto fallita\n"
#define MSGTR_MPDEMUX_MMST_MissingSignature "firma mancante\n"
#define MSGTR_MPDEMUX_MMST_PatentedTechnologyJoke "tutto fatto. Grazie per aver scaricato un file che contiene tecnologie proprietarie e brevettate.\n"
#define MSGTR_MPDEMUX_MMST_UnknownCmd "comando sconosciuto %02x\n"
#define MSGTR_MPDEMUX_MMST_GetMediaPacketErr "errore get_media_packet: %s\n"
#define MSGTR_MPDEMUX_MMST_Connected "connesso\n"

// asf_streaming.c

#define MSGTR_MPDEMUX_ASF_StreamChunkSize2Small "Ahhhh, la dimensione stream_chunk � troppo piccola: %d\n"
#define MSGTR_MPDEMUX_ASF_SizeConfirmMismatch "disallineamento size_confirm!: %d %d\n"
#define MSGTR_MPDEMUX_ASF_WarnDropHeader "Attenzione : scarto intestazione ????\n"
#define MSGTR_MPDEMUX_ASF_ErrorParsingChunkHeader "Errore durante l'interpretazione di una parte di intestazione\n"
#define MSGTR_MPDEMUX_ASF_NoHeaderAtFirstChunk "Non ho avuto un'intestazione come prima parte!!!!\n"
#define MSGTR_MPDEMUX_ASF_BufferMallocFailed "Errore non posso allocare un buffer di %d byte\n"
#define MSGTR_MPDEMUX_ASF_ErrReadingNetworkStream "Errore durante la lettura del flusso via rete\n"
#define MSGTR_MPDEMUX_ASF_ErrChunk2Small "Errore chunk troppo piccolo\n"
#define MSGTR_MPDEMUX_ASF_ErrSubChunkNumberInvalid "Errore il numero delle sotto-parti non � valido\n"
#define MSGTR_MPDEMUX_ASF_Bandwidth2SmallCannotPlay "banda troppo piccola, il file non pu� esser riprodotto!\n"
#define MSGTR_MPDEMUX_ASF_Bandwidth2SmallDeselectedAudio "banda troppo piccola, deselezionato flusso audio\n"
#define MSGTR_MPDEMUX_ASF_Bandwidth2SmallDeselectedVideo "banda troppo piccola, deselezionato flusso video\n"
#define MSGTR_MPDEMUX_ASF_InvalidLenInHeader "Lunghezza non valida nell'intestazione ASF!\n"
#define MSGTR_MPDEMUX_ASF_ErrReadingChunkHeader "Errore durante la lettura di una parte di intestazione\n"
#define MSGTR_MPDEMUX_ASF_ErrChunkBiggerThanPacket "Errore chunk_size > packet_size\n"
#define MSGTR_MPDEMUX_ASF_ErrReadingChunk "Errore durante la lettura di una parte (chunk)\n"
#define MSGTR_MPDEMUX_ASF_ASFRedirector "=====> ASF Ridirezionatore\n"
#define MSGTR_MPDEMUX_ASF_InvalidProxyURL "URL proxy non valido\n"
#define MSGTR_MPDEMUX_ASF_UnknownASFStreamType "Tipo del flusso asf sconosciuto\n"
#define MSGTR_MPDEMUX_ASF_Failed2ParseHTTPResponse "Fallita interpretazione della risposta HTTP\n"
#define MSGTR_MPDEMUX_ASF_ServerReturn "Il server risponde %d:%s\n"
#define MSGTR_MPDEMUX_ASF_ASFHTTPParseWarnCuttedPragma "AVVISO INTERPRETAZIONE ASF HTTP : Pragma %s tagliato da %d byte a %d\n"
#define MSGTR_MPDEMUX_ASF_SocketWriteError "Errore scrittura socket: %s\n"
#define MSGTR_MPDEMUX_ASF_HeaderParseFailed "Interpretazione intestazione fallita\n"
#define MSGTR_MPDEMUX_ASF_NoStreamFound "Nessun flusso trovato\n"
#define MSGTR_MPDEMUX_ASF_UnknownASFStreamingType "Modo do fornire il flusso ASF sconociuto\n"
#define MSGTR_MPDEMUX_ASF_InfoStreamASFURL "STREAM_ASF, URL: %s\n"
#define MSGTR_MPDEMUX_ASF_StreamingFailed "fallimento, esco\n"

// audio_in.c

#define MSGTR_MPDEMUX_AUDIOIN_ErrReadingAudio "\nerrore leggendo l'audio: %s\n"
#define MSGTR_MPDEMUX_AUDIOIN_XRUNSomeFramesMayBeLeftOut "Recupero da un cross-run, alcuni fotogrammi possono essere stati persi!\n"
#define MSGTR_MPDEMUX_AUDIOIN_ErrFatalCannotRecover "Errore fatale, non posso recuperare!\n"
#define MSGTR_MPDEMUX_AUDIOIN_NotEnoughSamples "\nnon ci sono abbastanza parti audio!\n"

// aviheader.c

#define MSGTR_MPDEMUX_AVIHDR_EmptyList "** lista vuota?!\n"
#define MSGTR_MPDEMUX_AVIHDR_FoundMovieAt "Trovato filmato a 0x%X - 0x%X\n"
#define MSGTR_MPDEMUX_AVIHDR_FoundBitmapInfoHeader "trovato 'bih', %u byte di %d\n"
#define MSGTR_MPDEMUX_AVIHDR_RegeneratingKeyfTableForMPG4V1 "Ricostruisco tabella keyframe per video M$ mpg4v1\n"
#define MSGTR_MPDEMUX_AVIHDR_RegeneratingKeyfTableForDIVX3 "Ricostruisco tabella keyframe per video DIVX3\n"
#define MSGTR_MPDEMUX_AVIHDR_RegeneratingKeyfTableForMPEG4 "Ricostruisco tabella keyframe per video MPEG4\n"
#define MSGTR_MPDEMUX_AVIHDR_FoundWaveFmt "trovato 'wf', %d byte di %d\n"
#define MSGTR_MPDEMUX_AVIHDR_FoundAVIV2Header "AVI: dmlh trovato (dimensione=%d) (fotogrammi totali=%d)\n"
#define MSGTR_MPDEMUX_AVIHDR_ReadingIndexBlockChunksForFrames "Leggo blocco INDEX, %d parti per %d fotogrammi (fpos=%"PRId64")\n"
#define MSGTR_MPDEMUX_AVIHDR_AdditionalRIFFHdr "intestazione RIFF supplementare...\n"
#define MSGTR_MPDEMUX_AVIHDR_WarnNotExtendedAVIHdr "** attenzione: questa non � un'intestazione AVI estesa..\n"
#define MSGTR_MPDEMUX_AVIHDR_BrokenChunk "Parte (chunk) danneggiata?  chunksize=%d  (id=%.4s)\n"
#define MSGTR_MPDEMUX_AVIHDR_BuildingODMLidx "AVI: ODML: Costruisco indice odml (%d superindexchunks)\n"
#define MSGTR_MPDEMUX_AVIHDR_BrokenODMLfile "AVI: ODML: Rilevato file rovinato (incompleto?). Sar� usato un indice tradizionale\n"
#define MSGTR_MPDEMUX_AVIHDR_CantReadIdxFile "Impossibile leggere il file indice %s: %s\n"
#define MSGTR_MPDEMUX_AVIHDR_NotValidMPidxFile "%s non � un file indice di MPlayer valido\n"
#define MSGTR_MPDEMUX_AVIHDR_FailedMallocForIdxFile "Impossibile allocare la memoria per i dati dell'indice da %s\n"
#define MSGTR_MPDEMUX_AVIHDR_PrematureEOF "Fine prematura del file indice %s\n"
#define MSGTR_MPDEMUX_AVIHDR_IdxFileLoaded "Caricato file indice: %s\n"
#define MSGTR_MPDEMUX_AVIHDR_GeneratingIdx "Genero indice: %3lu %s     \r"
#define MSGTR_MPDEMUX_AVIHDR_IdxGeneratedForHowManyChunks "AVI: Tabella indice generata per %d parti (chunks)!\n"
#define MSGTR_MPDEMUX_AVIHDR_Failed2WriteIdxFile "Non ho potuto scrivere il file indice %s: %s\n"
#define MSGTR_MPDEMUX_AVIHDR_IdxFileSaved "Salvato file indice: %s\n"

// cache2.c

#define MSGTR_MPDEMUX_CACHE2_NonCacheableStream "\rNon posso riempire la cache per questo flusso.\n"
#define MSGTR_MPDEMUX_CACHE2_ReadFileposDiffers "!!! read_filepos � differente!!! Riporta questo errore...\n"

// cdda.c

#define MSGTR_MPDEMUX_CDDA_CantOpenCDDADevice "Impossibile aprire il dispositivo CDDA.\n"
#define MSGTR_MPDEMUX_CDDA_CantOpenDisc "Impossibile aprire il disco.\n"
#define MSGTR_MPDEMUX_CDDA_AudioCDFoundWithNTracks "Trovato CD audio con %ld tracce.\n"

// cddb.c

#define MSGTR_MPDEMUX_CDDB_FailedToReadTOC "Imposibile leggere la TOC.\n"
#define MSGTR_MPDEMUX_CDDB_FailedToOpenDevice "Apertura del dispositivo %s fallita.\n"
#define MSGTR_MPDEMUX_CDDB_NotAValidURL "URL non valido\n"
#define MSGTR_MPDEMUX_CDDB_FailedToSendHTTPRequest "Fallimento nell'invio della richiesta HTTP.\n"
#define MSGTR_MPDEMUX_CDDB_FailedToReadHTTPResponse "Fallimento nella lettura della risposta HTTP.\n"
#define MSGTR_MPDEMUX_CDDB_HTTPErrorNOTFOUND "Non Trovato.\n"
#define MSGTR_MPDEMUX_CDDB_HTTPErrorUnknown "Codice di errore sconosciuto\n"
#define MSGTR_MPDEMUX_CDDB_NoCacheFound "Cache non trovata.\n"
#define MSGTR_MPDEMUX_CDDB_NotAllXMCDFileHasBeenRead "Non tutti i file xmcd sono stati letti.\n"
#define MSGTR_MPDEMUX_CDDB_FailedToCreateDirectory "Creazione della directory %s fallita.\n"
#define MSGTR_MPDEMUX_CDDB_NotAllXMCDFileHasBeenWritten "Non tutti i file xmcd sono stati scritti.\n"
#define MSGTR_MPDEMUX_CDDB_InvalidXMCDDatabaseReturned "Ricevuto file database xmcd non valido.\n"
#define MSGTR_MPDEMUX_CDDB_UnexpectedFIXME "'FIXME' inatteso\n"
#define MSGTR_MPDEMUX_CDDB_UnhandledCode "Codice non gestito\n"
#define MSGTR_MPDEMUX_CDDB_UnableToFindEOL "Impossibile trovare il carattere di 'fine linea'\n"
#define MSGTR_MPDEMUX_CDDB_ParseOKFoundAlbumTitle "Lettura OK, trovato: %s\n"
#define MSGTR_MPDEMUX_CDDB_AlbumNotFound "Album non trovato\n"
#define MSGTR_MPDEMUX_CDDB_ServerReturnsCommandSyntaxErr "Il server ha risposto: Errore sintassi comando ('Command syntax error')\n"
#define MSGTR_MPDEMUX_CDDB_NoSitesInfoAvailable "Nessuna informazione disponibile sul sito\n"
#define MSGTR_MPDEMUX_CDDB_FailedToGetProtocolLevel "Fallimento nell'ottenere il livello del protocollo\n"
#define MSGTR_MPDEMUX_CDDB_NoCDInDrive "Nessun CD nel lettore\n"

// cue_read.c

#define MSGTR_MPDEMUX_CUEREAD_UnexpectedCuefileLine "[bincue] Linea del file cue inattesa: %s\n"
#define MSGTR_MPDEMUX_CUEREAD_BinFilenameTested "[bincue] Verificato nome del file bin: %s\n"
#define MSGTR_MPDEMUX_CUEREAD_CannotFindBinFile "[bincue] Impossibile trovare il file bin - mi arrendo\n"
#define MSGTR_MPDEMUX_CUEREAD_UsingBinFile "[bincue] Uso il file bin %s\n"
#define MSGTR_MPDEMUX_CUEREAD_UnknownModeForBinfile "[bincue] Modalit� del file bin sconosciuta. Non dovrebbe capitare. Annullamento.\n"
#define MSGTR_MPDEMUX_CUEREAD_CannotOpenCueFile "[bincue] Impossibile aprire %s\n"
#define MSGTR_MPDEMUX_CUEREAD_ErrReadingFromCueFile "[bincue] Errore in lettura da %s\n"
#define MSGTR_MPDEMUX_CUEREAD_ErrGettingBinFileSize "[bincue] Errore nell'ottenere la dimensione del file bin\n"
#define MSGTR_MPDEMUX_CUEREAD_InfoTrackFormat "traccia %02d:  formato=%d  %02d:%02d:%02d\n"
#define MSGTR_MPDEMUX_CUEREAD_UnexpectedBinFileEOF "[bincue] Fine inaspettata del file bin\n"
#define MSGTR_MPDEMUX_CUEREAD_CannotReadNBytesOfPayload "[bincue] Non ho potuto leggere %d byte di payload\n"
#define MSGTR_MPDEMUX_CUEREAD_CueStreamInfo_FilenameTrackTracksavail "CUE stream_open, nomefile=%s, traccia=%d, tracce disponibili: %d -> %d\n"

// network.c

#define MSGTR_MPDEMUX_NW_UnknownAF "Famiglia d'indirizzi %d sconosciuta\n"
#define MSGTR_MPDEMUX_NW_ResolvingHostForAF "Risolvo %s per %s...\n"
#define MSGTR_MPDEMUX_NW_CantResolv "Impossibile risolvere il nome per %s: %s\n"
#define MSGTR_MPDEMUX_NW_ConnectingToServer "Connessione al server %s[%s]: %d ...\n"
#define MSGTR_MPDEMUX_NW_CantConnect2Server "Connessione al server fallita con %s\n"
#define MSGTR_MPDEMUX_NW_SelectFailed "Selezione fallita.\n"
#define MSGTR_MPDEMUX_NW_ConnTimeout "Timeout connessione.\n"
#define MSGTR_MPDEMUX_NW_GetSockOptFailed "Fallimento di getsockopt: %s\n"
#define MSGTR_MPDEMUX_NW_ConnectError "Errore di connessione: %s\n"
#define MSGTR_MPDEMUX_NW_InvalidProxySettingTryingWithout "Impostazioni proxy non valide... Provo senza proxy.\n"
#define MSGTR_MPDEMUX_NW_CantResolvTryingWithoutProxy "Non ho potuto risolvere il nome host remoto per AF_INET. Provo senza proxy.\n"
#define MSGTR_MPDEMUX_NW_ErrSendingHTTPRequest "Errore nell'invio della richiesta HTTP: non � stata inviata tutta la richiesta.\n"
#define MSGTR_MPDEMUX_NW_ReadFailed "Lettura fallita.\n"
#define MSGTR_MPDEMUX_NW_Read0CouldBeEOF "http_read_response ha letto uno 0 (per esempio EOF)\n"
#define MSGTR_MPDEMUX_NW_AuthFailed "Autenticazione fallita. Per favore usa le opzioni -user e -passwd per fornire\nun nome utente/password per una lista di URL, o indica un URL come questo:\nhttp://utente:password@nomehost/file\n"
#define MSGTR_MPDEMUX_NW_AuthRequiredFor "Autenticazione richiesta per %s\n"
#define MSGTR_MPDEMUX_NW_AuthRequired "Autenticazione richiesta.\n"
#define MSGTR_MPDEMUX_NW_NoPasswdProvidedTryingBlank "Nessuna password fornita, provo senza.\n"
#define MSGTR_MPDEMUX_NW_ErrServerReturned "Risposta del server %d: %s\n"
#define MSGTR_MPDEMUX_NW_CacheSizeSetTo "Dimensione cache impostata a %d KByte\n"

