/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.StackUsingArray;

/**
 *
 * @author sigma
 */
public class CircularQueue {
    private int[] queue = new int[5] ;
    private int front = 0 , rear = queue.length - 1 , count = 0 ;
    
    public void enqueue(int x)
    {
        if(isFull()) System.out.println("THE QUEUE IS FULL."); 
        else
                {rear = (rear+1) % queue.length ;
        queue[rear] = x ;
        count ++ ;}
    }
    
    public void dequeue()
    {
        if(isEmpty()) System.out.println("THE QUEUE IS ALREADY EMPTY.");
        else
        {front = (front+1) % queue.length ;
        count--;}
    }
    
    public void getFront(Integer x)
    {
        if(isEmpty()) System.out.println("THE QUEUE IS ALREADY EMPTY."); 
        else x. = queue[front] ;
    }
    
    public boolean isFull()
    {
        return count == queue.length ;
    }
    
    public boolean isEmpty()
    {
        return count == 0 ;
    }
    
    
}
