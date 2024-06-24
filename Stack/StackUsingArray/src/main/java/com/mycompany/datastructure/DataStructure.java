/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.StackUsingArray;

/**
 *
 * @author sigma
 */
public class DataStructure {
    static boolean isPaired(char open , char close)
    {
        if (open == '(' && close == ')') return true ;
        else if(open == '[' && close == ']') return true ;
        else if (open == '{' && close == '}') return true ;
        return false ;
    }
    static boolean isCorrect(String str)
    {
        Stack S1 = new Stack();
        for(int x = 0  ;  x < str.length() ; x++)
        {
            if(str.charAt(x) == '{' || str.charAt(x) == '(' ||str.charAt(x) == '[' )
            {S1.push((char)str.charAt(x));}
            else if(str.charAt(x) == '}' || str.charAt(x) == ')' ||str.charAt(x) == ']' )
            {if(!isPaired((char)S1.getTop(),str.charAt(x)) || S1.isEmpty())
            {return false ;}
                else 
            {S1.pop();}}
                   
        }
        return S1.isEmpty() ;
    }
    
    
    
   static char plus = '+' , minus = '-' , mult = '*' , divi = '/'  ;
    
    static String inToPost(String str)
    {
        char temp ;
        String result ="";
        Stack s1 = new Stack();
        for(int i = 0 ; i < str.length() ; i ++)
        {
            if(str.charAt(i) >= '0' && str.charAt(i) <= '9')
            {
                result += String.valueOf((char)str.charAt(i));
                result += " ";
            }
            else if (str.charAt(i) == '+' || str.charAt(i) == '-' || str.charAt(i) == '*' || str.charAt(i) == '/')
            {
                if(s1.isEmpty())
                {
                    s1.push((char)str.charAt(i));
                    continue;
                }
                else
                {
                  temp = (char)s1.getTop() ;
                  if( ( (str.charAt(i) == divi || str.charAt(i) == minus || str.charAt(i) == plus || str.charAt(i) == mult) && (temp == '*' || temp == '/') )  ||  (( str.charAt(i) == plus || str.charAt(i) == minus ) && (temp == plus || temp == minus)))
                  {
                      s1.pop();
                      result += String.valueOf((char)temp) ;
                      result += " " ;
                      s1.push(str.charAt(i));
                  }
                  else if((str.charAt(i) == divi || str.charAt(i) == mult) && (temp == plus || temp == minus))
                  {
                      result += String.valueOf((char)temp) ;
                      s1.pop();
                      result += " ";
                      s1.push(str.charAt(i));
                  }
                }
        }
    }
        while(!s1.isEmpty())
        {
            result += String.valueOf((char)s1.getTop());
            result += " " ;
            s1.pop();
        }
    
        return result ;
    }
    
    
    
    
    
    public static void main(String[] args) {
        CircularQueue c1 = new CircularQueue();
        Integer x = new Integer(1);
        c1.dequeue();
        c1.enqueue(54);
        c1.enqueue(86);
        c1.enqueue(43);
        c1.getFront(x);
        System.out.println(x.intValue());
        c1.enqueue(91);
        c1.enqueue(72);
        c1.enqueue(12);
        c1.dequeue();
        c1.getFront(x);
        System.out.println(x);
//        c1.dequeue();
//        System.out.println( c1.getFront());
//        c1.dequeue();
//        System.out.println( c1.getFront());
//        c1.dequeue();
//        System.out.println( c1.getFront());
//        c1.dequeue();
//        System.out.println( c1.getFront());
//        c1.dequeue();
//        System.out.println( c1.getFront());
        
        
    }
}
