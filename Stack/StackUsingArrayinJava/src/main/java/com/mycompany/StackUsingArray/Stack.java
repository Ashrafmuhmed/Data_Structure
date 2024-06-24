/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.datastructure;

/**
 *
 * @author sigma
 */
public class Stack {
    private int top ; 
    private char item[] = new char[100] ;

    public Stack() {
        this.top = -1 ;
    }
     public void push(char ele)
     {
         if(top == item.length - 1) System.out.println("The stack is full !!");
         else 
         {
             top ++ ;
             item[top] = ele ;
         }
     }
     
     public void pop()
     {
         if(this.isEmpty()) System.out.println("The stack is already empty");
         else top-- ;
     }
    
     public int getTop()
     {
         if(this.isEmpty()) return -1 ;
         else return item[top];
     }
     
     public boolean isEmpty()
     {
         return (top == -1) ? true : false ;
     }
     
     void print()
     {
         for(int i = top ; i >= 0  ; i--) System.out.print(item[i] + " ");
         System.out.println("");
             
                 
     }
}
