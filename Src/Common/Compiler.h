/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Compiler.h
 *       Module:  Common - Compiler Abstraction
 *
 *  Description:  This file contains the definitions and macros
 *                for the abstraction of compiler specific keywords.  
 *  
 *********************************************************************************************************************/
#ifndef COMPILER_H
#define COMPILER_H


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* The memory class is used for the declaration of local pointers */
#define AUTOMATIC

/* The memory class is used within type definitions, where no memory
   qualifier can be specified */
#define TYPEDEF

/* NULL_PTR define with a void pointer to zero definition*/
#define NULL_PTR          ((void *)0)

/* INLINE  define for abstraction of the compiler keyword inline*/
#define INLINE            inline

/* LOCAL_INLINE define for abstraction of the keyword inline in functions with "static" scope.
   Different compilers may require a different sequence of the keywords "static" and "inline" 
   if this is supported at all. */
#define LOCAL_INLINE      static inline

/* This is used to define the abstraction of compiler keyword static */
#define STATIC            static



#endif  /* COMPILER_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
