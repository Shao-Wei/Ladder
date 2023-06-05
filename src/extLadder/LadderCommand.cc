#include "base/abc/abc.h"
#include "base/main/main.h"
#include "base/main/mainInt.h"

ABC_NAMESPACE_IMPL_START

static Abc_Ntk_t * DummyFunction( Abc_Ntk_t * pNtk )
{
    Abc_Print( -1, "Please rewrite DummyFunction() in file \"LadderCommand.cc\".\n" );
    return NULL;
}

static int Ladder_Template_Command( Abc_Frame_t_ * pAbc, int argc, char ** argv )
{
    int c            = 0;
    int fVerbose     = 0;

    Abc_Ntk_t *pNtk, *pNtkRes;
        
    Extra_UtilGetoptReset();
    while ( ( c = Extra_UtilGetopt( argc, argv, "vh" ) ) != EOF )
    {
        switch ( c )
        {            
            case 'v':
                fVerbose ^= 1;
                break;
            case 'h':
                goto usage;
            default:
                goto usage;
        }
    }
    
    // init message
    printf("This is a template command for Ladder.\n");

    pNtk = Abc_FrameReadNtk(pAbc);
    if(pNtk == NULL)
    {
        printf("Error: Empty network.\n");
        return 0;
    }

    if ( !Abc_NtkIsStrash(pNtk) ) {
        Abc_Ntk_t * pNtkTemp = Abc_NtkStrash( pNtk, 0, 1, 0 );
        pNtk = pNtkTemp;
    }

    // main method
    pNtkRes = Abc_NtkDup(pNtk);

    Abc_FrameReplaceCurrentNetwork(pAbc, pNtkRes);
    return 0;
    
usage:
    Abc_Print( -2, "usage: ladder_template [-ivh]\n" );
    Abc_Print( -2, "\t              Template command for Ladder\n" );
    Abc_Print( -2, "\t-v            : verbosity [default = %d]\n", fVerbose );
    Abc_Print( -2, "\t-h            : print the command usage\n" );
    return 1;   
}

// called during ABC startup
static void init(Abc_Frame_t* pAbc)
{ 
    Cmd_CommandAdd( pAbc, "Ladder", "ladder_template", Ladder_Template_Command, 1);
}

// called during ABC termination
static void destroy(Abc_Frame_t* pAbc)
{
}

// this object should not be modified after the call to Abc_FrameAddInitializer
static Abc_FrameInitializer_t Ladder_frame_initializer = { init, destroy };

// register the initializer a constructor of a global object
// called before main (and ABC startup)
struct Ladder_registrar
{
    Ladder_registrar() 
    {
        Abc_FrameAddInitializer(&Ladder_frame_initializer);
    }
} Ladder_registrar_;

ABC_NAMESPACE_IMPL_END
